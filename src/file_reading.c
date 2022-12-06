/*
 * =====================================================================================
 *
 *       Filename:  file_punctuation_replacer.c
 *
 *    Description: A C program to play with files
 *
 *        Version:  1.0
 *        Created:  11/20/2022 11:11:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *from, *to;
  char c;

  from = fopen("assets/input.txt", "r");
  to = fopen("assets/output.txt", "w");

  if (from == NULL || to == NULL) {
    fprintf(stderr, "error: one file did not open.\n");
    return -1;
  }

  while ((c = fgetc(from)) != EOF) {
    if (c == '.')
      c = '!';
    fputc(c, to);
  }

  fclose(from);
  fclose(to);
}
