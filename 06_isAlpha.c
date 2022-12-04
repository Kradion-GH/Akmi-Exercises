#include "helper_functions.h"

/*
    Exercise #6

    Να φτιαχτεί ένα πρόγραμμα που να δέχεται από τον χρήστη ένα χαρακτήρα και
    να ελέγχει αν είναι μέρος του Αλφάβητου.
*/

void main(void) {
     
     for(;;) {
        char* s = get_string("Enter a character: ");
        if(strlen(s) > 1) {printf("Entered too many characters.\n"); continue;}

        isalpha(s[0]) ? printf("%c is a letter of the alphabet.\n", s[0]) : printf("%c is NOT a letter of the alphabet.\n", s[0]);
        break;
     }
}