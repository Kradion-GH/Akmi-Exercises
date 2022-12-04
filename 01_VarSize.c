#include <stdio.h>
#include <stdlib.h>

/*
    Exercise #1

    Να φτιαχτεί ένα πρόγραμμα που να παίρνει σαν είσοδο από το χρήστη τρεις
    αριθμούς ένα float , integer , char και να υπολογίζει το μέγεθος που
    καταλαμβάνουν στην μνήμη.
*/

void main() {
    
    // Get 3 variables from the user
    float f;
    int i;
    char c;

    printf("Enter a float: ");
    scanf("%f", &f);

    printf("Enter an integer: ");
    scanf("%i", &i);

    printf("Enter a character: ");
    scanf("\n%c", &c);

    // Print the size of each variable aswell as the total
    printf("\n");
    printf("The float %f is composed of %d bytes.\n", f, sizeof(f));
    printf("The integer %d is composed of %d bytes.\n", i, sizeof(i));
    printf("The character \'%c\' is composed of %d bytes.\n", c, sizeof(c));
    printf("In total all three variables use %d bytes of memory.\n", sizeof(f) + sizeof(i) + sizeof(c));
    printf("\n");

    // ---
    system("pause");
}