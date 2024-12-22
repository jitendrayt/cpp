// Header file 

// Header file are used to declare functions and types which are to be used in multiple cpp files
// it only needs the declarations and not the actual definitions similar to what you would need in a cpp file
// if you're using a function variable which was declared outside of that file.
// esentially #include "header.h" does the same thing it copies the entire content of header file to the cpp file
// at compile time.

#pragma once // anything with a # is a pre-processor directive, will be preprocessed by pre-processor 
// before compiltion, pragma once is a header guard it prevents copying the header file multiple times in a
// translation unit (cpp files) avoiding redefinition in chain of includes from different files.


// another type of header guard is with #ifndef, the entire code between #ifndef - #endif will not be copied
// more than once since on the first copy we define REVISE_H with #define.
#ifndef REVISE_H
#define REVISE_H // #define is valid for the entire file.

struct Entity {};

#endif








// just an example of how the header file will be copied into a cpp file in case of multiple inclusions
// any code in below block will not get compiled since REVISE_H is already defined above.
// similar to below
// #include revise.h
// #include revise.h
// removinf the header guards from above will give errors.
#ifndef REVISE_H
#define REVISE_H

struct Player {};


#endif


