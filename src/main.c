#include <stdio.h>
#include "sort.h"

int main(int argc, char *argv[]) {
  // set the desired sorting algorithm to "_sort" function pointer
  // to test multiple implementations
  void (* _sort)(void *, int, int, int (*comp)(void *, void *)) = merge_sort;

  //# sorting int array
  int arr_int[] = {5, 3, 6, 1, 8};
  // print the original array first
  printf("#int\nOriginal: [");
  for (int i = 0; i < 5; i++) {
    printf("%s%d", i > 0 ? ", ": "", arr_int[i]);
  }
  // perform the sort
  _sort(arr_int, 5, sizeof(int), comp_int);
  // print the sorted array
  printf("]\nSorted: [");
  for (int i = 0; i < 5; i++) {
    printf("%s%d", i > 0 ? ", ": "", arr_int[i]);
  }
  printf("]\n\n");



  //# sorting string array
  char *arr_char[] = {"ahmed", "abuelfateh", "solve", "example", "block"};
  // print the original array
  printf("#string\nOriginal: [");
  for (int i = 0; i < 5; i++) {
    printf("%s'%s'", i > 0 ? ", ": "", arr_char[i]);
  }
  // perform the sort
  _sort(arr_char, 5, sizeof(char *), comp_str);
  // print the sorted array
  printf("]\nSorted: [");
  for (int i = 0; i < 5; i++) {
    printf("%s'%s'", i > 0 ? ", ": "", arr_char[i]);
  }
  printf("]\n\n");


  return 0;
}