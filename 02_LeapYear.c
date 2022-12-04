#include <stdio.h>
#include <stdlib.h>

/*
    Exercise #2

    Να φτιαχτεί ένα πρόγραμμα που να δεχεται χρονολογίες από το χρήστη και να
    βρίσκει αν είναι δίσεκτες.
*/

void main() {

    // get a year from the user
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // check if the entered year is a leap year or a common year and print the correct message
    printf("\n");
    (!(year % 4) && ((year % 100) || (!(year % 100) && !(year % 400)))) ? printf("%d is a leap year.\n", year) : printf("%d is a common year.\n", year);
    printf("\n");

    // ---
    system("pause");
}