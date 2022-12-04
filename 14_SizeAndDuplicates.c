#include "helper_functions.h"

/*
    Exercise #14

    Γράψτε ένα πρόγραμμα σε που να διαβάζει n αριθμούς από το χρήστη να τους
    αποθηκεύει σε ένα πίνακα να εκτυπώνει το συνολικό μέγεθος του πίνακα και να
    εκτυπώνει τα διπλότυπα
*/



void main(void) {
    struct integer_vector* numbers = get_array_of_integers();

    fputs("2\ny\n3\ny\n64\ny\n3\ny\n75\ny\n65\ny\n64\ny\n2\ny\n534\ny\n45\nn\n", stdin);

    printf("The array has %d elements and a total size of %d bytes.\n", numbers->size, numbers->size * sizeof(int));

    int* duplicates = (int*)malloc((numbers->size) * sizeof(int));
    int dup_idx = 0;

    for(int i = 0; i < numbers->size - 1; i++) {
        if(is_num_in_array(numbers->data + i + 1, numbers->size - i - 1, numbers->data[i])) {
            if(!is_num_in_array(duplicates, dup_idx, numbers->data[i])) {
                duplicates[dup_idx] = numbers->data[i];
                dup_idx++;
            }
        }
    }

    if(dup_idx){
        printf("Duplicates:\n");
        for(int i = 0; i < dup_idx; i++) printf("%d ", duplicates[i]);
    } else {
        printf("There were no duplicates.\n");
    }

    system("pause");
}
