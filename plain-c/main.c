/*
 * main.c
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "starry.h"

int main(void) {
  if (N < N_MIN || N > N_MAX) {
    fprintf(stderr, "starry: N must be an integer between %d and %d\n", N_MIN,
            N_MAX);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      fprintf(stdout, "*");
    }
    fprintf(stdout, "\n");
  }

  exit(EXIT_SUCCESS);
}
