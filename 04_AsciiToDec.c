#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper_functions.h"

/*
    Exercice #4

    Να φτιαχτεί ένα πρόγραμμα το οποίο να δέχεται χαρακτήρες από το χρήστη και
    να εκτυπώνει τις ASCII τιμές τους.
*/

int main() {

    for(;;) {
        // get a character from the user
        char* s = get_string("Enter a character or \'quit\': ");
        if(s == NULL) {
            #ifdef error_logging
            fprintf(stderr, "\n!get_string failed at %s:%d", __FILE__, __LINE__ - 3);
            #endif
            return 1;
        }

        // check if the user wants to quit
        if(!strcmp(s, "quit"))
            break;

        // print ascii value
        if(s[1] == '\0') printf("<%c>\'s ascii value is %d.\n", s[0], s[0]);
        else printf("Invalid input.\n");

        free(s);
    }
    return 0;
}