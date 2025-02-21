#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// string functions

// wrong way to make strings
// pointer stored in the locals frame of the function, will lead to segmentation fault
char *make_string_wrong(int sz) {
    char str[sz];
    return str;
}

// correct way is to use malloc
char *make_String_right(int sz) {
    char *str = (char *) malloc(sz*sizeof(char));
    return str;
}

int main() {
    // Strings
    // Defining string using address of character
    char *str = "abc";
    // not allowed to do str[1] = x
    printf("%c\n", str[1]); // allowed to print str[1]
    printf("%zu\n", sizeof(str)); // 8 (pointers are long ints)
    // the string is placed somewhere in memory that is not in the locals frame
    // thus it is immutable

    // Defining String using array
    char str2[] = "abc";
    str2[0] = 'x'; // allowed
    printf("%s\n", str2); // "xbc" now
    printf("%zu\n", sizeof(str2)); // 4 now, each address block is 1 byte
    // string is placed in the main locals frame
    // can change it like a regular array

    // Defining String using Malloc
    char *str3 = (char *) malloc(3*sizeof(char)); // same as malloc(3)
    str3[0] = 'a';
    str3[1] = 'b';
    str3[2] = 'c';
    printf("%s\n", str3); // abc
    printf("%zu\n", sizeof(str3)); // still 8 (size of the pointer)
    // weird I didn't need the null character
    free(str3);

    // Using String Function
    char *str4 = make_String_right(3);
    str4[0] = 'a';
    str4[1] = 'b';
    str4[2] = 'c';
    printf("%s\n", str4);
    // remember to free
    free(str4);
    

    return 0;
}