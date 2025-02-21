#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int BOOL;

typedef struct uoft_student {
    char st_number_str[11];
    int faculty_num;
} uoft_student;

// functions on struct (must pass in pointer)
void drop_to_artsci(uoft_student *p_s) {
    p_s->faculty_num = 1;
}

// pointers in structures
typedef struct waterloo_student {
    char *st_number_str;
} waterlooser;

// changing student number
void change_w_id_bad(waterlooser w) {
    w.st_number_str = (char *) malloc(5*sizeof(char));
    strcpy(w.st_number_str, "666");
}
// allocating memory will only change what the local frame pointers points to
// consequently, the original w.st_number_str wil still point to what it originally was

// correct way
void change_w_id_good(waterlooser w) {
    strcpy(w.st_number_str, "666");
}
// directly copy the st_number to the address (works!)

// creating structs with double pointers
void create_waterlooser(waterlooser **p_p_w) {
    *p_p_w = (waterlooser *) malloc(sizeof(waterlooser));
    (*p_p_w)->st_number_str = (char *) malloc(5*sizeof(char));
    // equivilent (*(*p_p_w)).st_number_str = (char *)malloc(5 * sizeof(char));
}

// destroy waterlooser
void destroy_waterlooser(waterlooser *p_w) {
    free(p_w -> st_number_str);
    free(p_w);
}
// must free p_w -> st_number_str first, as if we free p_w first we can no longer free 
// where st_number_str points to

void print_uoft_student(uoft_student s) {
    printf("student number: %s\n", s.st_number_str);
    printf("faculty number: %d\n", s.faculty_num);
}

int main() {
    uoft_student s;
    s.faculty_num = 0;
    strcpy(s.st_number_str, "1234567890");
    print_uoft_student(s);

    // testing waterlooser creation
    waterlooser *w;
    create_waterlooser(&w);
    return 0;
}