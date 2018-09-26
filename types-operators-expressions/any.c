/* 
 * Write the function any(s1, s2), which returns the first location in the 
 * string s1 where any character from the string s2 occurs, or -1 if s1 
 * contains no characters from s2.
 * */

// TODO: Write function to sort string characters in alphabetical order then binary 
// search char

#include <stdio.h>

int any(char s1[], char s2[]);
int indexof(char s[], char c);

/* test any */
int main() {
  char s1[] = "abcdef";
  char s2[] = "def";
  printf("%d\n", any(s1, s2));

  return 0;
}

int indexof(char s[], char c) {
  int i = 0;
  char ch;

  while ((ch = s[i++]) != '\0') {
    if (ch == c) {
      return --i;
    }
  }

  return -1;
}

int any(char s1[], char s2[]) {
  int i = 0;
  char c;

  while ((c = s1[i++]) != '\0') {
    int idx = indexof(s2, c); 
    if (idx != -1) {
      return --i;
    }
  }

  return -1;
}
