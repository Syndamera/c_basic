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
    printf("Kelvin > Celsius: %.4f\n", c);
    
    c = FahrenheitToCelsius(50);
    printf("Fahrenheit > Celsius: %.4f\n", c);
    
    float k = FahrenheitToKelvin(50);
    printf("Fahrenheit > Kelvin: %.4f\n", k);
    
    float f = KelvinToFahrenheit(283.15);
    printf("Kelvin > Fahrenheit: %.4f\n", f);
    
    TypeSizes();
    printf("Macro Test: %d\n", SQUARE(4));
}