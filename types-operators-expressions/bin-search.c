/* Our binary search makes two tests inside the loop, when one 
 * would siffice (at the price of more tests outside). Write a 
 * version with only one test inside the loop ad measure the
 * difference in run-time. */

#include <stdio.h>

int binsearch(int x, int arr[], int len);

int main() {
  int nums[] = { 3, 5, 7, 9, 11, 13, 15, 17 };
  int filternum = 13;

  int position = binsearch(filternum, nums, 8); 

  printf("Occured at: %d\n", position);

  return 0;
}

int binsearch(int x, int arr[], int len) {
  int low, mid, high;

  low = 0;
  high = len - 1; 

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= arr[mid])
      high = mid;
    else   
      low = mid + 1;
  } 

  return (x == arr[low]) ? low : -1;
}
