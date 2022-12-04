#include <stdio.h>
#include <stdlib.h>
#include "helper_functions.h"

/*
    Exercise #8

    Να φτιαχτεί ένα πρόγραμμα που να δέχεται ένα string και να εκτυπώνει το
    μέγεθός του.
*/

void main(void) {
    char* s = get_string("Enter a string: ");

    printf("The string you entered consists of %d characters and is made of %d bytes.\n", strlen(s), strlen(s));
    system("pause");
}