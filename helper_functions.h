#ifndef helper_functions
#define helper_functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//#define error_logging

struct integer_vector {
    int* data;
    int size;
};

char* itos(int n);

/*
    Get a string from the user. Discards the new line character.

    Returns the inputted string or NULL on failure.
*/
char* get_string(const char* prompt) {

    printf(prompt);
    int n = 4;
    char* s = (char*)malloc(n);
    if(s == NULL) {
        #ifdef error_logging
            fprintf(stderr, "\n!memory allocation error at %s:%d", __FILE__, __LINE__ - 3);
        #endif
        return NULL;
    }
    int i = 0;
    for(;;) {
        if(i == n) {
            n *= 2;
            char* ret = (char*)realloc(s, n);
            if(ret == NULL) {
                free(s);
                #ifdef error_logging
                    fprintf(stderr, "\n!memory allocation error at %s:%d", __FILE__, __LINE__ - 4);
                #endif
                return NULL;
            }
            s = ret;
        }

        int c = fgetc(stdin);
        if(c == EOF) {
            free(s);
            #ifdef error_logging
                fprintf(stderr, "\n!stdin read error at %s:%d", __FILE__, __LINE__ - 4);
            #endif
            return NULL;
        }
        if(i == 0 && c == '\n') {printf("You have to enter something.\n%s", prompt); continue;}
        else if(c == '\n') {s[i] = '\0'; break;}
        else s[i] = c;

        i++;
    }

    char* ret = (char*)realloc(s, i + 1);
    if(ret == NULL) {
        free(s);
        #ifdef error_logging
            fprintf(stderr, "\n!memory allocation error at %s:%d", __FILE__, __LINE__ - 4);
        #endif
        return NULL;
    }
    return ret;
}

int get_integer(char* prompt) {
    char* input;
    for(;;) {
        input = get_string(prompt);
        
        for(int i = 0; i <= strlen(input); i++) {
            if(input[i] == '\0') {
                int integer = atoi(input);
                char* its = itos(integer);
                if(strcmp(input, its)) {printf("The number you entered is out of bounds for an int (min: %d, max: %d).\n", INT_MIN, INT_MAX); free(input); free(its); break;}
                free(its); free(input);
                return integer;
            }
            
            if(!isdigit(input[i])) {
                if(i == 0 && (input[i] == '-' || input[i] == '+')) {i++; continue;}
                printf("Non-digit entered.\n");
                free(input);
                break;
            }
        }
    }
}

char* itos(int n) {
    char* s = (char*)malloc(12);
    if(s == NULL) {
        #ifdef error_logging
            fprintf(stderr, "\n!memory allocation error at %s:%d", __FILE__, __LINE__ - 3);
        #endif
        return NULL;
    }
    if(n == 0) {s[0] = '0'; s[1] = '\0'; return s;}
    int i = 0, j = 0;
    if(n < 0) {s[0] = '-'; i++; j++;}
    unsigned int un = abs(n);

    while(un > 0) {
        s[i] = (un % 10) + '0';
        un /= 10;
        i++;
    }
    s[i] = '\0';
    i--;
    char temp;
    while(j < i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i--; j++;
    }

    return s;
}

struct integer_vector* get_array_of_integers() {
    struct integer_vector* arr = (struct integer_vector*)malloc(sizeof(struct integer_vector*));
    arr->data = NULL;
    arr->size = 0;
    char* input;

    do
    {
        arr->size++;
        int num = get_integer("Enter an integer: ");
        arr->data = (int*)realloc(arr->data, arr->size * sizeof(int));
        arr->data[arr->size - 1] = num;
        for(;;) {
            char choice;
            input = get_string("Enter another integer? (y/n): ");
            if(strlen(input) > 1 || !(input[0] == 'y' || input[0] == 'n')) {printf("Invalid choice.\n"); free(input); continue;}
            break;
        }
    } while (input[0] == 'y');

    return arr;
}

char* int_to_bin(int n) {
    char* bin = (char*)malloc(33);
    bin[32] = '\0';
    int bin_idx = 0;
    int negative = 0;
    if(n < 0) negative = 1;
    n = abs(n); 

    while(n > 0) {
        bin[bin_idx] = '0' + n%2;
        bin_idx++;
        n /= 2;
    }    

    while(bin_idx < 32) {
        bin[bin_idx] = '0';
        bin_idx++;
    }

    for(int i = 0; i < 32 / 2; i++) {
        int temp = bin[i];
        bin[i] = bin[31 - i];
        bin[31 - i] = temp;
    }

    if(negative) bin[0] = '1';

    return bin;
}

int is_num_in_array(int* arr, int size, int target) {
    for(size--; size >= 0; size--)
        if(arr[size] == target) return 1;
    return 0;
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int min(int a, int b) {
    return (a < b ? a : b);
}

#endif