/*
* @file main.c
* @brief Main file for Lab 5
* 
* Course: CPE2600
* Section: 111
* Assignment: Lab 5
* Name: Dillon Fayas
*
* Compile: gcc main.c -o lab5
*/
 
#include <stdio.h>
#include "operations.h"
#include "commands.h"
#include "vectors.h"

int main(void) {

    char input[300];

    while (strcmp(input, "quit")) {
        printf("minimat> ");
        scanf("%s", input);

        char index0[50];
        char index1[50];
        char index2[50];
        char index3[50];
        char index4[50];

        // parse input  --------------------------------------------------------- commas?
        sscanf(input, "%s %s %s %s %s", index0, index1, index2, index3, index4);

        // check return values for function success --------------------------------------------

        if (!strcmp(index1, "\0")) {
            // check input for commands
            if (!strcmp(index0, "list")) {
                list();
            } else if (!strcmp(input0, "help")) {
                help();
            } else if (!strcmp(input0, "clear")) {
                clear();
            } else {
                if (vect_name(input0) == 0) {           // input is an existing variable
                    // print an error because vect_name returns 1 if successful -----------------------
                }
            }
        } else if (!strcmp(index1, "=")) {              // math with new vect assignment
            if (!strcmp(index3, "+")) {
                set_vect(index0, add_vect(index2, index4));
            } else if (!strcmp(index3, "-")) {
                set_vect(index0, sub_vect(index2, index4));
            } else if (!strcmp(index3, ".")) {
                set_vect(index0, dot_vect(index2, index4));
            } else if (!strcmp(index3, "*")) {
                set_vect(index0, cross_vect(index2, index4));
            } else {
                new_vect(index0, index2, index3, index4);
            }
        } else if (!strcmp(index1, "+")) {              // math with no new vect assignment
            add_vect(index0, index2);
        } else if (!strcmp(index1, "-")) {
            sub_vect(index0, index2);
        } else if (!strcmp(index1, ".")) {
            dot_vect(index0, index2);
        } else if (!strcmp(index1, "*")) {
            cross_vect(index0, index2);
        }

        // error handling goes down here
        
    }
    return 0;
}
 