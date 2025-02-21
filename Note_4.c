#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print array function
void print_array(int *arr, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// print string function
void manual_print_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

// string funciton using pointer arithemtic (makes more sense)
void print_str(char *str) {
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

// string length functions
int manual_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i; 
}

// or short cut 
int manual_strlen2(char *str) {
    int i = 0;
    while (*str++) {
        i++;
    }
    return i;
}

int main() {
    // test string function
    char *str = "Guerzhoy";
    manual_print_str(str);
    print_str(str);
    printf("%d\n", manual_strlen(str));
    printf("%d\n", manual_strlen2(str));
    return 0;
}