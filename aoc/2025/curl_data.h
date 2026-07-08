#include <curl/curl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* data;
  size_t size;
} Buffer;

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
  size_t total = size * nmemb;
  Buffer* buf = (Buffer*)userp;

  char* tmp = realloc(buf->data, buf->size + total + 1);
  if (!tmp) return 0;

  buf->data = tmp;

  memcpy(buf->data + buf->size, contents, total);
  buf->size += total;
  buf->data[buf->size] = '\0';

  return total;
}

char* get_data(const char* link) {
  CURL* curl = curl_easy_init();
  if (!curl) return NULL;

  Buffer buffer = {NULL, 0};

  curl_easy_setopt(curl, CURLOPT_URL, link);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

  const char* session = getenv("session");
  if (!session) {
    fprintf(stderr, "session not set\n");
    curl_easy_cleanup(curl);
    return NULL;
  }

  char cookie[1024];
  snprintf(cookie, sizeof(cookie), "session=%s", session);
  curl_easy_setopt(curl, CURLOPT_COOKIE, cookie);

  CURLcode res = curl_easy_perform(curl);

  curl_easy_cleanup(curl);

  if (res != CURLE_OK) {
    free(buffer.data);
    return NULL;
  }

  return buffer.data;  // Caller must free()
}
