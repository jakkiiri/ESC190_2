#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Question 1
a)
x = 20, 6
b) 
99, 169
c)
This is true.
d) 
I don't think so
e)
Error
f)
3...
2...
1...
Go!
g)
10, 10, 20
5, 5, 20
5, 20, 20
h)
0, 1.5, 2.7e14, 9999
*/

// Question 2

void describe (int grade) {
    if (grade < 0 || grade > 100) {
        printf("Invalid.\n");
    } else if (grade >= 50) {
        printf("Pass!\n");
    } else {
        printf("Fail...\n");
    }
}

void decompose (long number, int *area, int *first, int *second) {
    *second = number % 10000;
    number /= 10000;
    *first = number % 1000;
    number /= 1000;
    *area = number;
}

// Question 3
void censor () {
    char filename[100];
    scanf("%s", filename);
    FILE *fptr;
    char complete_filename[100];
    strcpy(complete_filename, filename);
    strcat(complete_filename, ".txt");
    fptr = fopen(complete_filename, "r");   
    char str[120];
    fgets(str, 120, fptr);
    fclose(fptr);
    // loop through str
    for (int i = 0; i < 120; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            str[i] = '#';
        }
    }
    printf("%s\n", str);
}

int main () {
    // Question 2
    describe(53);
    describe(200);
    describe(-1);
    describe(35);
    
    /*
    double list[50];
    for (int i = 0; i < 50; i++) {
        scanf("%lf", &list[i]);
    }

    for (int i = 0; i < 50; i++) {
        printf("%lf, ", list[i]);
    }

    printf("\n");
    */
    int area, first, second;
    decompose(4169783707L, &area, &first, &second);
    printf("(%d) %d-%4d\n", area, first, second);

    censor();
    return 0;
}