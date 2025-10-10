/*
* @file commands.c
* @brief Commands implementation file
* 
* Course: CPE2600
* Section: 111
* Assignment: Lab 5
* Name: Dillon Fayas
*/

#include <stdio.h>
#include "operations.h"
#include "commands.h"
#include "vectors.h"

/*
* @brief Clear all stored vectors
*/
void clear(vect vectors[], int num_vectors) {
    for (int i = 0; i < num_vectors; i++) {
        vectors[i].name[0] = '\0';
        vectors[i].x = 0;
        vectors[i].y = 0;
        vectors[i].z = 0;
    }
    printf("All vectors cleared.\n");
}

/*
* @brief Display help information
*/
void help() {
    printf("Vector Command Help Menu:\n");
    printf("Available commands:\n");
    printf("\t<name> = <x> <y> <z>\t\tCreate a new vector with the given name and components.\n");

    printf("\nAssignment operations:\n");
    printf("\t<name> = <name> + <name>\tAdd two vectors\n");
    printf("\t<name> = <name> - <name>\tSubtract two vectors\n");
    printf("\t<name> = <name> . <name>\tDot product of two vectors\n");
    printf("\t<name> = <name> * <name>\tCross product of two vectors\n");
    printf("\t<name> = <name> * <scalar>\tScale a vector\n");

    printf("\nDisplay operations:\n");
    printf("\t<name>\t\t\t\tView an existing vector\n");
    printf("\t<name> + <name>\t\t\tAdd two vectors\n");
    printf("\t<name> - <name>\t\t\tSubtract two vectors\n");
    printf("\t<name> . <name>\t\t\tDot product of two vectors\n");
    printf("\t<name> * <name>\t\t\tCross product of two vectors\n");
    printf("\t<name> * <scalar>\t\tScale a vector\n");

    printf("\nMiscellaneous operations:\n");
    printf("\tclear\t\t\t\tClear all stored vectors\n");
    printf("\tquit\t\t\t\tExit the program\n");
    printf("\tlist\t\t\t\tList all stored vectors\n");

    printf("\nNote: Only spaces and commas are allowed as separators in commands\n\n");
}

/*
* @brief List all stored vectors
* @param vectors - The array of stored vectors
* @param num_vectors - The number of stored vectors
*/
void list(vect vectors[], int num_vectors) {
    if (num_vectors == 0) {
        printf("No vectors stored.\n");
        return;
    }
    for (int i = 0; i < num_vectors; i++) {
        if (vectors[i].name[0] != '\0') {
            print_vect(vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
        }
    }

}