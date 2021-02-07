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
    TempratureTable(10, 10);
    
    float c = KelvinToCelsius(274.15f);
    printf("Kelvin > Celsius: %.2f\n", c);
    
    c = FahrenheitToCelsius(42);
    printf("Fahrenheit > Celsius: %.2f\n", c);
    
    TypeSizes();
    printf("Macro Test: %d\n", SQUARE(4));
}