#include "helper_functions.h"

/*
    Exercise #13

    Γράψτε ένα πρόγραμμα σε που να διαβάζει n αριθμούς από το χρήστη να τους
    αποθηκεύει σε ένα πίνακα , μετά να τους αντιγράφει σε ένα δεύτερο και να
    εκτυπώνει το συνολικό τους άθροισμα.
*/

void main(void) {
    // original array
    struct integer_vector* arr = get_array_of_integers();

    // coppied array (newly allocated memory, doesn't point to old one)
    struct integer_vector* arr_copy = (struct integer_vector*)malloc(sizeof(struct integer_vector*));
    arr_copy->size = arr->size;
    arr_copy->data = (int*)malloc(arr_copy->size * sizeof(int));
    memcpy(arr_copy->data, arr->data, arr->size * sizeof(int));
    // --------------------------------------

    long long sum = 0;
    for(int i = 0; i < arr_copy->size; i++) sum += arr_copy->data[i];

    printf("The sum of the entered integers is: %lld\n", sum);

    system("pause");
}