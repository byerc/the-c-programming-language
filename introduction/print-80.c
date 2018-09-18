#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define PRINT_LIMIT 80 /* print line if limit is reached */

int getlinelen(char line[], int maxline);

/* print lines that are of length 80 or more */
int main() {
  int len; /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = getlinelen(line, MAXLINE)) > 0) 
    if (len >= PRINT_LIMIT) {
      printf("%s", line);
    }

  return 0;
}

/* getline: read a line into s, return length */
int getlinelen(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) 
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
