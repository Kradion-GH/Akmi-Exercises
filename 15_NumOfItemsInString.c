#include "helper_functions.h"

/*
    Exercise #15

    Γράψτε ένα πρόγραμμα που να διαβάζει μια αλφαριθμιτική σειρά από το χρήστη
    και να εκτυπώνει το πλήθος τών αριθμών των γραμμάτων και των ειδικών
    χαρακτήρων που υπάρχουν σε αυτή.
*/

void main(void) {
    char* s = get_string("Enter a string: ");
    int letters = 0, digits = 0, special = 0;

    for(int i = 0; i < strlen(s); i++) {
        if(isalpha(s[i])) letters++;
        else if(isdigit(s[i])) digits++;
        else special++;
    }

    printf("The entered string has %d letters, %d digits and %d special characters.\n", letters, digits, special);

    system("pause");
}