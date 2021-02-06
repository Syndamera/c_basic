#include <stdio.h>
#include "ansic/chapter01_notes.c"
#include "pluralsight.h"

int global_int = 0; // accessible in all files.
static int static_global_int; // accessible only in this file.

int main(int argv, char*argc)
{
    // Ansi C - Chapter 01
    //PrintFahrCelsius();
    
    // Pluralsight
    Pluralsight(10);
    TypeSizes();
    printf("Macro Test: %d\n", SQUARE(4));
}