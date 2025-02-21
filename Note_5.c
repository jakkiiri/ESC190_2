#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// copying strings
char *str_cpy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // make sure to add null to destination
    dest[i] = '\0';
    return dest;
}

// do while version (make sure it's ran at least once)
char *str_cpy1(char *dest, char*src) {
    int i = 0;
    do {
        dest[i] = src[i];
        i++;
    } while (src[i - 1] != '\0');
    return dest;
}

// Modifying Arrays usng double pointers
int *get_int_arr_from_input(int **p_arr, int *p_n) {
    printf("Number of elements you want in the array: ");
    scanf("%d", p_n);
    *p_arr = (int *) malloc(*p_n * sizeof(int));
    // create the array of elements based on the elements the user wants
    for (int i = 0; i < *p_n; i++) {
        scanf("%d", &(*p_arr)[i]);
    }
}

int main() {
    // test copy functions
    char str1[100];
    char str2[] = "Hello World";
    char str3[20];
    str_cpy(str1, str2);
    str_cpy1(str3, str2);
    printf("%s\n", str1);
    printf("%s\n", str3);
    
    // reading input using scanf
    int a;
    scanf("%d", &a);
    printf("You entered: %d\n", a);

    float f;
    scanf("%f", &f);
    printf("You entered: %f\n", f);

    char s[100];
    scanf("%s", &s);
    printf("You entered: %s\n", s);

    char *p_a = (char *) malloc(100);
    scanf("%s", p_a);
    printf("You entered: %s\n", p_a);

    int *p_int = (int*) malloc(sizeof(int));
    scanf("%d", p_int);
    printf("You entered: %d\n", *p_int);

    // Reading input using double pointers
    int *arr;
    int n;
    get_int_arr_from_input(&arr, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}