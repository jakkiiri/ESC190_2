#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1 {
    char name[5];
    int f;
} student1;

typedef struct student2 {
    char *name;
    int f;
} student2;

void set_name2a(student2 s) {
    strcpy(s.name, "abc");
}

int main() {
    student1 s1;
    printf("%lu, %lu, %u\n", (unsigned long)(&s1), (unsigned long)(&(s1.name)), (unsigned long)(&(s1.f)));
    // why is this cooked?
    printf("%lu\n", (unsigned long)sizeof(s1));

    student2 s2;
    s2.name = (char *)malloc(5*sizeof(char)); // without this line we will get segmentation fault
    // must allocate memory for floating pointers
    set_name2a(s2);
    printf("%s\n", s2.name);
    free(s2.name);
    return 0;
}