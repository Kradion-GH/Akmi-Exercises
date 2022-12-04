#include "helper_functions.h"

/*
    Exercide #9

    Να φτιαχτεί ένα πρόγραμμα που να δέχεται βαθμούς σε θερμοκρασίας σε
    κελσίου και να την μετατρέπει σε κέλβιν.
*/

void main(void) {

    int celcius;

    for(;;) {
        // TODO: change to float and use -273.15 instead
        celcius = get_integer("Enter a temperature in celcius: ");
        if(celcius < -273) {printf("The temperature you entered is too low (min -273).\n"); continue;}
        printf("%d degrees celcius is equal to %lld degrees kelvin.\n", celcius, celcius + 273);
        break;
    }
}