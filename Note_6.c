#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct uoft_student {
    char st_number_str[11];
    int faculty_num;
};

void print_uoft_student(struct uoft_student s) {
    printf("student number: %s\n", s.st_number_str);
    printf("faculty number: %d\n", s.faculty_num);
}

int main() {
    struct uoft_student s;
    s.faculty_num = 0;
    // s.st_number_str = "1234567890" // error
    strcpy(s.st_number_str, "1234567890");
    print_uoft_student(s);
    return 0;
}