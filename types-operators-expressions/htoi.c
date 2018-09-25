/**
 * Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A through F. 
 */

#include <stdio.h>

int htoi(char hex[]);
int stringlen(char s[]);

/* test hexadecimal to int function*/
int main() {
  char hex1[] = "0xaf";
  char hex2[] = "af";
  char hex3[] = "0xFF";
  char hex4[] = "0xAH"; 

  printf("%d\n", htoi(hex1)); /* should be 175 */
  printf("%d\n", htoi(hex2)); /* should be 175 */
  printf("%d\n", htoi(hex3)); /* should be 255 */
  printf("%d\n", htoi(hex4)); /* should be invalid */

  return 0;
}

/* Converts a hexadecimal string to integer. Returns 0 for invalid strings */
int htoi(char hex[]) {
  int t = 0;
  int start = 0;

  if (stringlen(hex) > 2) {
    char first = hex[0];
    char second = hex[1];
    if (first == '0' && (second == 'x' || second == 'X')) {
      start = 2;
    }
  }

  int i;
  char c;
  for (i = start; (c = hex[i]) != '\0'; i++) {
    int d;

    if ('0' <= c && c <= '9') {
      d = c - '0';
    } else if ('a' <= c && c <= 'f') {
      d = 10 + c - 'a';
    } else if ('A' <= c && c <= 'F') {
      d = 10 + c - 'A';
    } else {
      printf("Invalid hexadecimal string \n");
      return 0;
    }

    t = t * 16 + d;
  }

  return t;
}

/* Intentionally not using stdlib */
int stringlen(char s[]) {
  int i;

  i = 0;
  while (s[i] != '\0') 
    ++i;

  return i; 
} 
