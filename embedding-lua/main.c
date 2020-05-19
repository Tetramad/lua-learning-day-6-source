/*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "starry.h"

int main(void) {
  int N;

  N = load_config();
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      fprintf(stdout, "*");
    }
    fprintf(stdout, "\n");
  }

  exit(EXIT_SUCCESS);
}
