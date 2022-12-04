#include "helper_functions.h"

/*
    Exercise #12

    Γράψτε ένα πρόγραμμα σε που να διαβάζει n αριθμούς από το χρήστη να τους
    αποθηκεύει σε ένα πίνακα και να τους εκτυπώνει το συνολικό τους άθροισμα.
*/

void main(void) {
    struct integer_vector* arr = get_array_of_integers();

    long long sum = 0;
    for(int i = 0; i < arr->size; i++) sum += arr->data[i];

    printf("The sum of the entered integers is: %lld\n", sum);

    system("pause");
}