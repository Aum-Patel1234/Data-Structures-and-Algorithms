#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "curl_data.h"
#include "vector.h"

const char* link = "https://adventofcode.com/2025/day/2/input";

typedef u_int64_t u64;

typedef struct {
  u64 begin, end;
  size_t i;
  char* input;
} Pair;

void next(Pair* p) {
  size_t start = p->i;
  while (p->input[p->i] != '-') p->i++;

  p->input[p->i] = '\0';
  // p->begin = atoi(&p->input[start]);
  p->begin = strtoull(&p->input[start], NULL, 10);
  p->input[p->i] = '-';

  p->i++;  // skip -

  start = p->i;
  while (p->input[p->i] != ',' && p->input[p->i] != '\0') p->i++;

  char c = p->input[p->i];
  p->input[p->i] = '\0';
  // p->end = atoi(&p->input[start]);
  p->end = strtoull(&p->input[start], NULL, 10);
  p->input[p->i] = c;

  if (c == ',') p->i++;  // skip if ,
}

u8 isSymetric(u64 num) {
  const size_t full_size = 32;
  char buffer[full_size];
  // buffer[127] = '\0';
  size_t i = full_size - 1;

  if (num == 0) buffer[i--] = '0';

  while (num) {
    buffer[i--] = (char)((num % 10) + '0');
    num /= 10;
  }

  size_t start = i + 1;
  size_t size = full_size - start;

  if (size % 2 != 0) return 0;

  size_t half = size / 2;
  size_t k = start;
  size_t j = start + half;

  while (k < start + half) {
    if (buffer[k++] != buffer[j++]) return 0;
  }

  return 1;
}

int main() {
  char* input = get_data(link);

  if (!input) {
    printf("NULL data from link\n");
    return 0;
  }

  // printf("%s\n", input);
  Pair p = {.input = input, .i = 0, .begin = 0, .end = 0};
  unsigned long long ans = 0;
  while (input[p.i] != '\0') {
    next(&p);
    printf("begin=%llu, end=%llu\n", (unsigned long long)p.begin, (unsigned long long)p.end);

    for (u64 i = p.begin; i <= p.end; ++i) {
      if (isSymetric(i)) ans += i;
    }
    printf("No of symmetric nums=%llu\n", ans);
  }
  // printf("No of symmetric nums=%u\n", ans);

  free(input);
  return 0;
}
