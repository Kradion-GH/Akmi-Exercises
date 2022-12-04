#include "helper_functions.h"

/*
    Exercice #10

    Γράψτε ένα πρόγραμμα που να αποθηκεύει 7 στοιχεία σε ένα πίνακα και να τα
    εκτυπώνει.
*/

void main(void) {
    char** elements = (char**)malloc(7 * sizeof(char*));

    for(int i = 0; i < 7; i++) elements[i] = get_string("Enter a string: ");

    printf("You entered this elements:\n");
    for(int i = 0; i < 7; i++) printf("%s\n", elements[i]);

    system("pause");
}