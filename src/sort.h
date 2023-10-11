/**
 * @author Ahmed Abuelfateh
 */
#ifndef ABUELFATEH_SORT_H
#define ABUELFATEH_SORT_H 1

int comp_str(void *, void *);
int comp_wchar_t(void *, void *);

int comp_int(void *, void *);
int comp_long(void *, void *);
int comp_float(void *, void *);
int comp_double(void *, void *);
int comp_size_t(void *, void *);


void bubble_sort(void *arr, int length, int size, int (*comp)(void *, void *));
void selection_sort(void *arr, int length, int size, int (*comp)(void *, void *));
void insertion_sort(void *arr, int length, int size, int (*comp)(void *, void *));
void merge_sort(void *arr, int length, int size, int (*comp)(void *, void *));

#endif //!ABUELFATEH_SORT_H 1