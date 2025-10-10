/*
* @file operations.c
* @brief Operations implementation file
* 
* Course: CPE2600
* Section: 111
* Assignment: Lab 5
* Name: Dillon Fayas
*/

#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "commands.h"
#include "vectors.h"
 
/*
* @brief Create a new vector
* @param name - The name of the vector
* @param x - The x component of the vector
* @param y - The y component of the vector
* @param z - The z component of the vector
* @return 1 on success, 0 on failure
*/
vect new_vect(char name[50], float x, float y, float z) {
    vect temp;
    strcpy(temp.name, name);
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}
 
/*
* @brief Check if a vector with the given name exists
* @param name - The name of the vector to check
* @param vectors - The array of vectors to search
* @return 1 if the vector exists, 0 otherwise
*/
int find_vect(vect vectors[], char name[50], int size) {
    for (int i = 0; i < size; i++) {
        if (vectors[i].name[0] == '\0') continue;
        if (strcmp(name, vectors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}
 
/*
* @brief Add two vectors
* @param a - The first vector
* @param b - The second vector
* @return The resulting vector
*/
vect add_vect(vect a, vect b) {
    vect temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    temp.z = a.z + b.z;
    return temp;
}
 
/*
* @brief Subtract two vectors
* @param a - The first vector
* @param b - The second vector
* @return The resulting vector
*/
vect sub_vect(vect a, vect b) {
    vect temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    temp.z = a.z - b.z;
    return temp;
}
 
/*
* @brief Dot product of two vectors
* @param a - The first vector
* @param b - The second vector
* @return The dot product of the two vectors
*/
float dot_vect(vect a, vect b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
 
/*
* @brief Cross product of two vectors
* @param a - The first vector
* @param b - The second vector
* @return The cross product of the two vectors
*/
vect cross_vect(vect a, vect b) {
    vect temp;
    temp.x = a.y * b.z - a.z * b.y;
    temp.y = a.z * b.x - a.x * b.z;
    temp.z = a.x * b.y - a.y * b.x;
    return temp;
}
 
/*
* @brief Scale a vector
* @param a - The vector to scale
* @param s - The scalar value
* @return The scaled vector
*/
vect scalar_vect(vect a, float s) {
    vect temp;
    temp.x = a.x * s;
    temp.y = a.y * s;
    temp.z = a.z * s;
    return temp;
}
 
/*
* @brief Print the components of a vector
* @param name - The name of the vector
* @param x - The x component of the vector
* @param y - The y component of the vector
* @param z - The z component of the vector
* @return 1 on success, 0 on failure
*/
void print_vect(char name[50], float x, float y, float z) {
    printf("%s = %.2f, %.2f, %.2f\n", name, x, y, z);
}