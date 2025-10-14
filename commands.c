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
    printf(" - <name> = <x> <y> <z>          ===   Create a new vector with the given name and components.\n");

    printf("\nAssign Variables:\n");
    printf(" - <name> = <name> + <name>      ===   Add two vectors\n");
    printf(" - <name> = <name> - <name>      ===   Subtract two vectors\n");
    printf(" - <name> = <name> . <name>      ===   Dot product of two vectors\n");
    printf(" - <name> = <name> * <name>      ===   Cross product of two vectors\n");
    printf(" - <name> = <name> * <scalar>    ===   Scale a vector\n");

    printf("\nOperations:\n");
    printf(" - <name>                        ===   View an existing vector\n");
    printf(" - <name> + <name>               ===   Add two vectors\n");
    printf(" - <name> - <name>               ===   Subtract two vectors\n");
    printf(" - <name> . <name>               ===   Dot product of two vectors\n");
    printf(" - <name> * <name>               ===   Cross product of two vectors\n");
    printf(" - <name> * <scalar>             ===   Scale a vector\n");
    printf(" - <scalar> * <name>             ===   Scale a vector\n");

    printf("\nHelper Commands:\n");
    printf(" - clear                         ===   Clear all stored vectors\n");
    printf(" - quit                          ===   Exit the program\n");
    printf(" - list                          ===   List all stored vectors\n");

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