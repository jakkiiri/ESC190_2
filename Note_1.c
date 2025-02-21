#include <stdio.h>
#include <stdlib.h>

// Make Array Wrong
// returns address of local variable
// segmentation fault
int *make_array_wrong() {
    int arr[5] = {1,2,3,4,5};
    return arr;
}

// To make array in function corectly, use malloc
// this allocates a block of memory on the heap as opposed to on the stack
// heap: Memory table that is not tied to the locals frame
// Stack: in the locals frame of the function
// no segmentation fault this time 
int *make_array_right() {
    int *arr = (int*) malloc(5*sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    return arr;
}


int main () {
    // Pointers
    int a = 42;
    int* p_a = &a; // stores address of a in p_a
    printf("%ld\n", p_a); // ld is a long integer, addresses are long
    // Example of Output: 140721628516612

    // dereferencing Operator
    int b = *p_a; // assigns b to the value which is stored in p_a
    printf("%d\n", b); // 42

    // Functions
    int *arr = make_array_right();
    printf("%d\n", arr[2]);
    // remember to free the memory after use
    free(arr);
    // accessing the freed memory is undefined behaviour
    return 0;
}