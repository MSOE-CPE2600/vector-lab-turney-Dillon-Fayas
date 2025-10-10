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
*
* Algorithm:
* 1. Initialize an array to store vectors and a counter for the number of vectors.
* 2. Enter an infinite loop to continuously prompt the user for input.
* 3. Read the user input and parse it into components.
* 4. Check for special commands like "quit", "help", "clear", and "list" and execute them.
* 5. For vector operations, check if the operation is an assignment or a display operation.
* 6. For assignment operations, check if the vector already exists. If it does, update it; if not, create a new vector.
* 7. For display operations, check if the vector exists and perform the requested operation, displaying the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operations.h"
#include "commands.h"
#include "vectors.h"

#define SIZE 10

vect parse_operation(vect vectors[], int vector_1_index, char operation[50], int vector_2_index);
bool is_float(char pattern[]);

int main(int argc, char *argv[]) {

    if (argc > 1) {
        if (!strcmp(argv[1], "-h")) {
            help();
        }
    }

    char input[256];
    vect vectors[SIZE];
    int num_vectors = 0;

    /* initialize vector names to empty to avoid reading uninitialized memory */
    for (int i = 0; i < SIZE; i++) {
        vectors[i].name[0] = '\0';
        vectors[i].x = 0;
        vectors[i].y = 0;
        vectors[i].z = 0;
    }

    while (1) {
        char index0[50] = "", index1[50] = "", index2[50] = "", index3[50] = "", index4[50] = "";

        printf("minimat> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == ',') {
                input[i] = ' ';
            }
        }
        sscanf(input, "%s %s %s %s %s", index0, index1, index2, index3, index4);

        if (!strcmp(index0, "quit")) {
            return 0;
        } else if (!strcmp(index0, "help")) {
            help();
            continue;
        } else if (!strcmp(index0, "clear")) {
            clear(vectors, num_vectors);
            num_vectors = 0;
            continue;
        } else if (!strcmp(index0, "list")) {
            list(vectors, num_vectors);
            continue;
        }

        int assignment_vector_index = find_vect(vectors, index0, SIZE);

        if (index1[0] == '\0') {
            if (assignment_vector_index != -1) {
                print_vect(vectors[assignment_vector_index].name, vectors[assignment_vector_index].x, vectors[assignment_vector_index].y, vectors[assignment_vector_index].z);
            } else {
                printf("Error: Vector not found\n");
                continue;
            }
        } else if (!strcmp(index1, "=")) {
            if (is_float(index3) && is_float(index2) && is_float(index4)) {
                if (num_vectors < SIZE) {
                    if (assignment_vector_index != -1) {
                        vectors[assignment_vector_index] = new_vect(index0, atof(index2), atof(index3), atof(index4));
                        num_vectors++;
                        continue;
                    }
                    vectors[num_vectors++] = new_vect(index0, atof(index2), atof(index3), atof(index4));
                } else {
                    printf("Error: Maximum number of vectors reached\n");
                    continue;
                }
            } else if (index3 != '\0') {
                int vector_1_index = find_vect(vectors, index2, SIZE);
                int vector_2_index = find_vect(vectors, index4, SIZE);
                vect temporary_vector;
                if (vector_1_index != -1 && vector_2_index == -1) {
                    temporary_vector = scalar_vect(vectors[vector_1_index], atof(index4));
                } else {
                    temporary_vector = parse_operation(vectors, vector_1_index, index3, vector_2_index);
                }
                if (strcmp(temporary_vector.name, " ") == 0) {
                    continue;
                }
                vectors[num_vectors++] = new_vect(index0, temporary_vector.x, temporary_vector.y, temporary_vector.z);
            }
        } else if (index1 != '\0') {
            int vector_1_index = find_vect(vectors, index0, SIZE);
            int vector_2_index = find_vect(vectors, index2, SIZE);
            vect temporary_vector;
                if (vector_1_index != -1 && vector_2_index == -1) {
                    temporary_vector = scalar_vect(vectors[vector_1_index], atof(index2));
                } else {
                    temporary_vector = parse_operation(vectors, vector_1_index, index1, vector_2_index);
                }
            if (strcmp(temporary_vector.name, " ") == 0) {
                continue;
            }
            char name[50] = "ans";
            print_vect(name, temporary_vector.x, temporary_vector.y, temporary_vector.z);
        } else {
            printf("Error: Something went wrong\n");
        }
    }
    
    return 0;
}

/*
* @brief Parse and execute a vector operation
* @param vectors - The array of stored vectors
* @param vector_1_index - The index of the first vector
* @param operation - The operation to perform
* @param vector_2_index - The index of the second vector
* @return The resulting vector
*/
vect parse_operation(vect vectors[], int vector_1_index, char operation[50], int vector_2_index) {
    if (!strcmp(operation, "+")) {
        return add_vect(vectors[vector_1_index], vectors[vector_2_index]);
    } else if (!strcmp(operation, "-")) {
        return sub_vect(vectors[vector_1_index], vectors[vector_2_index]);
    } else if (!strcmp(operation, ".")) {
        vect result;
        result.x = dot_vect(vectors[vector_1_index], vectors[vector_2_index]);
        result.y = 0;
        result.z = 0;
        return result;
    } else if (!strcmp(operation, "*")) {
        return cross_vect(vectors[vector_1_index], vectors[vector_2_index]);
    } else {
        printf("Error: Invalid operation\n");
        return new_vect(" ", 0, 0, 0);
    }
}

/*
* @brief Check if a string is a float
* @param pattern - The string to check
* @return true if the string is a float, false otherwise
*/
bool is_float(char pattern[]) {
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] < '0' || pattern[i] > '9') {
            return false;
        }
    }
    return true;
}

/*
* @brief Check if a string is empty
* @param pattern - The string to check
* @return true if the string is empty, false otherwise
*/
bool is_empty(char pattern[]) {
    return pattern[0] == '\0';
}