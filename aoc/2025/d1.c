#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "curl_data.h"
#include "vector.h"

const char* link = "https://adventofcode.com/2025/day/1/input";

typedef struct {
  char a[6];
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
  if (j > 0) {
    d.a[j] = '\0';
    vec_add_element(&vec, &d);
  }
  return vec;
}

// int get_num(const char* str) {
//   int num = 0;
//
//   for (int i = 1; str[i] != '\0'; ++i) {
//     num = (num * 10) + (str[i] - '0');
//   }
//
//   return str[0] == 'L' ? -num : num;
// }

int main() {
  char* input = get_data(link);

  if (!input) {
    printf("NULL data from link\n");
    return 0;
  }

  // char* input = "R1000\nL50\0";
  Vec vec = input_to_vec(input);
  // printf("vec size=%zu\n", vec.size);
  Data* arr = (Data*)vec.data;

  int ans = 0;
  int pos = 50;

  for (size_t i = 0; i < vec.size; i++) {
    char dir = arr[i].a[0];
    int amount = atoi(arr[i].a + 1);

    for (int j = 0; j < amount; j++) {
      if (dir == 'R')
        pos = (pos + 1) % 100;
      else
        pos = (pos + 99) % 100;  // -1 mod 100

      if (pos == 0) ans++;
    }
  }

  printf("%d\n", ans);

  printf("The ans for my input = %d\n", ans);
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
