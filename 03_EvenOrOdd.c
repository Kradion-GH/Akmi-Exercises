#include <stdio.h>
#include <stdlib.h>

/*
    Exercise #1

    Να φτιαχτεί ένα πρόγραμμα που να δεχεται έναν ακέραιo αριθμό από το χρήστη
    και να βρίσκει αν είναι περιττος ή άρτιος.
*/

void main() {
    
    // get a number from the user
    int i;
    printf("Enter an integer: ");
    scanf("%d", &i);

    // check if the entered number is even or odd and print the correct message
    i % 2 ? printf("%d is odd.\n", i) : printf("%d is even.\n", i);

    // ---
    system("pause");
}