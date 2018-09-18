#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX 20 /* maximum length of words to count for. discard others. */

int main() {
  int c, i, j;
  int length = 0;
  int wordlengths[MAX];
  int state = OUT;

  for (i = 0; i < MAX; ++i) 
    wordlengths[i] = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN && length >= 1 && length < MAX) {
        ++wordlengths[length];
      }
      length = 0;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++length;
    } else {
      ++length;
    }
  }

  printf("\n");
  for (i = 1; i < MAX; ++i) {
    printf("%2d | ", i);
    for (j = 0; j < wordlengths[i]; ++j) 
      printf("*");
    printf("\n");
  }

  return 0;
}
