#include <stdio.h>
#include <stdlib.h>

int main() {
    // Double Pointers
    int *a = 0;
    int **p_a = &a;

    printf("%ld\n", &a); // big ass number
    printf("%d\n", *p_a); // 0
    printf("%d\n", *(&a)); // ok this is pointless: 0

    // Fun thing with pointers
    int b[] = {5, 8, 13};
    int* p_b = b;
    printf("%d\n", p_b[0]); // [0] literally is the same as *p_b
    printf("%d\n", *p_b);
    // pointer arithmetic
    p_b++;
    printf("%d\n", *p_b); // 8
    printf("%d\n", p_b[0]); // 8
    printf("%d\n", p_b[1]); // 13
    // if we had done this with malloc with only allocating one int of space
    // it will crash as the pointer arithmetic does not refer to the block no more

    // Same thing with double pointers
    int **p_p_a = 0;
    // accessing p_p_a here gives an error
    p_p_a = (int **) malloc(sizeof(int*));
    // p_p_a is valid address, so we can access *p_p_a
    // allocate *p_p_a
    *p_p_a = (int *) malloc(sizeof(int));
    **p_p_a = 58;

    return 0;
}