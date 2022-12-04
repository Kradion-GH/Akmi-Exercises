#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helper_functions.h"

/*
    Exercice #5

    Να φτιαχτεί ένα πρόγραμμα που να δέχεται από τον χρήστη τρεις αριθμούς και
    εκτυπώνει τον μεγαλυτερο.
*/

void main(void) {
    int i[3];
    int i[0] = get_integer("Enter an int: ");
    int i[1] = get_integer("Enter a second int: ");
    int i[2] = get_integer("Enter a third int: ");

    printf("%d is the largest of the three given ints.\n", max(i[0], max(i[1], i[2])));

    system("pause");
}