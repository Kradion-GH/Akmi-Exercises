#include <stdlib.h>
#include <stdio.h>

/*
    Exercise #7
    
    Να φτιαχτεί ένα πρόγραμμα που να εκτυπώνει το γράμματα του Αγγλικού
    Αλφάβητου.
*/

void main(void) {
    printf("\n");
    printf("Lower Case Characters:\n");
    for(int i = 0; i < 26; i++) printf("%c", 'a' + i);
    printf("\n\n");
    printf("Upper Case Characters:\n");
    for(int i = 0; i < 26; i++) printf("%c", 'A' + i);
    printf("\n\n");

    system("pause");
}