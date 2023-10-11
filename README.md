
# Implementation of Generic sort algorithms in C Programming Language

Generic sorting algorithms written in C Programming Language

- Generic merge sort    
- Generic insertion sort  
- Generic selection sort  
- Generic bubble sort  

including basic types comparison functions     

- comp_int: for int data type    
- comp_long: for long data type    
- comp_float: for float data type   
- comp_double: for double data type    
- comp_size_t: for size_t data type    
- comp_str: for string (char *) data type    
- comp_wchar_t: for wide character string (wchar_t *) data type    


------------

sorting functions prototype are the same    

     XXXX_sort([TheArray], [ArrayLength], [ItemSizeInTheArray], [CompareFunction])


-------------

implemented sort methods are     

- merge_sort     
- insertion_sort     
- selection_sort     
- bubble_sort    

--------------- 

> main.c file include a basic usage examples


Example [int array]:    

    int arr[] = {7, 3, 6, 1, 9, 2, 5, 4, 8};
    const int ARRAY_LENGTH = 9;

    merge_sort((void *) arr, ARRAY_LENGTH, sizeof(int), comp_int);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");


Example [string array]:    

    char *arr[] = {"ahmed", "abuelfateh", "solve", "example", "block"};
    const int ARRAY_LENGTH = 5;

    merge_sort((void *) arr, ARRAY_LENGTH, sizeof(char *), comp_str);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
      printf("%s ", arr[i]);
    }
    printf("\n");
