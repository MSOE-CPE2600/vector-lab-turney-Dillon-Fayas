/*
* @file operations.h
* @brief Operations header file
* 
* Course: CPE2600
* Section: 111
* Assignment: Lab 5
* Name: Dillon Fayas
*/

#include "vectors.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H

vect new_vect(char name[50], float x, float y, float z);
int find_vect(vect vectors[], char name[50], int size);
vect add_vect(vect a, vect b);
vect sub_vect(vect a, vect b);
float dot_vect(vect a, vect b);
vect cross_vect(vect a, vect b);
vect scalar_vect(vect a, float s);
void print_vect(char name[50], float x, float y, float z);

#endif // OPERATIONS_H