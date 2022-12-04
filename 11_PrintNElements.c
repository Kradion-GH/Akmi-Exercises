#include "helper_functions.h"

/*
    Exercise #11

    Γράψτε ένα πρόγραμμα σε που να διαβάζει n αριθμούς από το χρήστη να τους
    αποθηκεύει σε ένα πίνακα και να τους εκτυπώνει με αντίστροφη σειρά .
*/

void main(void) {
    int idx = 0;
    int* numbers;
    char* input;

    do
    {
        int num = get_integer("Enter an integer: ");
        numbers = (int*)realloc(numbers, idx + 1);
        numbers[idx] = num;
        for(;;) {
            char choice;
            input = get_string("Enter another integer? (y/n): ");
            if(strlen(input) > 1 || !(input[0] == 'y' || input[0] == 'n')) {printf("Invalid choice.\n"); free(input); continue;}
            break;
        }
        idx++;
    } while (input[0] == 'y');

    printf("You entered the following numbers:\n");
    printf("[%d", numbers[0]);
    for(int i = 1; i < idx; i++) printf(", %d", numbers[i]);
    printf("]\n");

    system("pause");
}