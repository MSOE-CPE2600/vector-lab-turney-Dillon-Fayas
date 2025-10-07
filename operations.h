/*
* @file operations.h
* @brief Operations header file
* 
* Course: CPE2600
* Section: 111
* Assignment: Lab 5
* Name: Dillon Fayas
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H
 
// return 0 if unsuccessful, 1 if successful
int new_vect(char name[50], char x[50], char y[50], char z[50]); // check for valid floats
int vect_name(char name[50]);
vect add_vect(char name_a[50], char name_b[50]);
vect sub_vect(char name_a[50], char name_b[50]);
float dot_vect(char name_a[50], char name_b[50]); // return x = #, y = 0 and z = 0
vect cross_vect(char name_a[50], char name_b[50]);
vect scalar_vect(char name[50], char scalar[50]);
 
int set_vect(char name[50], vect new_vect);
    // check for vect length room
    // check for existing vect name
// int print_vect
    // ans = ...
 
#endif // OPERATIONS_H