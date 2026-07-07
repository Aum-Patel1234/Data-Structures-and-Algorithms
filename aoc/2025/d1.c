#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "curl_data.h"
#include "vector.h"

const char* link = "https://adventofcode.com/2025/day/1/input";

typedef struct {
  char a[5];
} Data;

Vec input_to_vec(char* input) {
  Vec vec = vec_init(sizeof(Data));

  size_t i = 0, j = 0;
  Data d = (Data){.a = "----\0"};

  while (input[i] != '\0') {
    if (input[i] == '\n') {
      d.a[j] = '\0';
      vec_add_element(&vec, &d);

      d = (Data){0};
      j = 0;
    } else
      d.a[j++] = input[i];

    i++;
  }
  return vec;
}

int get_num(const char* str) {
  int num = 0;

  for (int i = 1; str[i] != '\0'; ++i) {
    num = (num * 10) + (str[i] - '0');
  }

  return str[0] == 'L' ? -num : num;
}

int main() {
  char* input = get_data(link);

  if (!input) {
    printf("NULL data from link\n");
    return 0;
  }

  Vec vec = input_to_vec(input);
  Data* arr = (Data*)vec.data;

  int ans = 0;
  int start = 50;
  for (size_t i = 0; i < vec.size; i++) {
    // printf("%s\n", arr[i].a);
    char* data = arr[i].a;
    int num = get_num(data);
    // printf("%s - %d\n", data, num);

    start = (start + num) % 100;
    if (start == 0) ans++;
  }

  printf("The ans for my input = %d", ans);
  // NOTE: to get max size of any str
  // size_t i = 0;
  // int max_size = 0, curr_size = 0;
  // while (input[i] != '\0') {
  //   if (input[i] != '\n') {
  //     printf("%c", input[i]);
  //     curr_size++;
  //   } else {
  //     printf(" ");
  //     max_size = MAX(max_size, curr_size);
  //     curr_size = 0;
  //   }
  //   i++;
  // }
  //
  // printf("\n\nMax size = %d", max_size);

  free(input);
  vec_free(&vec);
  return 0;
}
