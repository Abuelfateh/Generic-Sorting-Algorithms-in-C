#include "sort.h"
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

int comp_str(void *a, void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int comp_wchar_t(void *a, void *b) {
  return wcscmp(*(wchar_t **)a, *(wchar_t **)b);
}

int comp_int(void *a, void *b) {
  // first cast the (void *) pointer to the original type: (int *)
  // then, dereference the pointer to compare the actual value
  return *(int *)a > *(int *)b ? 1 : (*(int *)a < *(int *)b ? -1 : 0);
}

int comp_long(void *a, void *b) {
  return *(long *)a > *(long *)b ? 1 : (*(long *)a < *(long *)b ? -1 : 0);
}

int comp_float(void *a, void *b) {
  return *(float *)a > *(float *)b ? 1 : (*(float *)a < *(float *)b ? -1 : 0);
}

int comp_double(void *a, void *b) {
  return *(double *)a > *(double *)b ? 1 : (*(double *)a < *(double *)b ? -1 : 0);
}

int comp_size_t(void *a, void *b) {
  return *(size_t *)a > *(size_t *)b ? 1 : (*(size_t *)a < *(size_t *)b ? -1 : 0);
}


void bubble_sort(void *arr, int length, int size, int (*comp)(void *, void *)) {
  int i, x, repeat;
  // cast array to unsigned char pointer (byte pointer)
  // as we perform pointer arithmetic based on size of bytes per element
  unsigned char *base = (unsigned char *)arr;
  // create a temporary buffer to perform swap
  unsigned char *buffer = (unsigned char *) malloc(size);
  if (NULL == buffer) {
    exit(-1);
  }

  // decrement length to allow direct access to next element in the array
  length--;
  do {
    repeat = 0;
    for (i = 0; i < length; i++) {
      // x is an intermediary variable to cache multiplication result
      x = i * size;
      if (comp(base + x, base + x + size) > 0) {
        memcpy(buffer, base + x, size);
        memcpy(base + x, base + x + size, size);
        memcpy(base + x + size, buffer, size);
        repeat = 1;
      }
    }
  } while (repeat);

  free(buffer);
}

void selection_sort(void *arr, int length, int size, int (*comp)(void *, void *)) {
  int i, j, x, index;
  unsigned char *base = (unsigned char *)arr;
  unsigned char *buffer = (unsigned char *) malloc(size);
  if (NULL == buffer) {
    exit(-1);
  }

  for (i = 0; i < length; i++) {
    index = i;
    for (j = i + 1; j < length; j++) {
      if (comp(base + (index * size), base + (j * size)) > 0) {
        index = j;
      }
    }

    // perform the swap only once if there exists a value less than the current value
    if (index != i) {
      memcpy(buffer, base + (i * size), size);
      memcpy(base + (i * size), base + (index * size), size);
      memcpy(base + (index * size), buffer, size);
    }
  }
  free(buffer);
}

void insertion_sort(void *arr, int length, int size, int (*comp)(void *, void *)) {
  int i, j;
  unsigned char *base = (unsigned char *)arr;
  unsigned char *buffer = (unsigned char *) malloc(size);
  if (NULL == buffer) {
    exit(-1);
  }

  for (i = 1; i < length; i++) {
    memcpy(buffer, base + (i * size), size);

    for (j = i - 1; j >= 0 && comp(base + (j * size), buffer) > 0; j--) {
      memcpy(base + (j * size) + size, base + (j * size), size);
    }

    memcpy(base + (j * size) + size, buffer, size);
  }

  free(buffer);
}

void internal_merge_sort(int left, int right, void *arr, int size, int (*comp)(void *, void *)) {
  int middle, i, j, k,
    left_length, right_length;

  unsigned char *L, *R, *base = (unsigned char *)arr;

  if (right <= left) return;

  // calculate the middle position
  middle = (left + right) >> 1;

  // sort the left half
  internal_merge_sort(left, middle, arr, size, comp);
  // sort thr right half
  internal_merge_sort(middle + 1, right, arr, size, comp);
  
  // merge the sorted halfs

  left_length = middle - left + 1;
  right_length = right - middle;

  L = (unsigned char *)malloc(left_length * size);
  if (NULL == L) {
    exit(-1);
  }
  R = (unsigned char *)malloc(right_length * size);
  if (NULL == R) {
    free(L);
    exit(-1);
  }

  // copy left half content
  for (i = 0; i < left_length; i++)
    memcpy(L + (i * size), base + ((left + i) * size), size);

  // copy right half content
  for (i = 0; i < right_length; i++)
    memcpy(R + (i * size), base + ((middle + i + 1) * size), size);


  i = 0;
  j = 0;
  k = left;

  // move elements from temporary sorted halfs to the original array
  while (i < left_length && j < right_length) {
    if (comp(R + (j * size), L + (i * size)) > 0) {
      memcpy(base + (size * k++), L + (size * i++), size);
    }
    else {
      memcpy(base + (size * k++), R + (size * j++), size);
    }
  }

  // move the remaining elements in the left half
  while (i < left_length) {
    memcpy(base + (size * k++), L + (size * i++), size);
  }

  // move the remaining elements in the right half
  while (j < right_length) {
    memcpy(base + (size * k++), R + (size * j++), size);
  }

  free(L);
  free(R);
}

/**
 * merge_sort is defined as wrapper to internal_merge_sort
 * to accept the same parameters as other sort algorithms
 */
void merge_sort(void *arr, int length, int size, int (*comp)(void *, void *)) {
  internal_merge_sort(0, length -1, arr, size, comp);
}