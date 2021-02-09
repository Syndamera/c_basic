#include <stdio.h>
#include "ansic/chapter01_notes.c"
#include "pluralsight.h"

int global_int = 0; // accessible in all files.
static int static_global_int; // accessible only in this file.

typedef struct
{
    char c;
    int i;
} PluralStruct;

void PrintStructSize(PluralStruct s)
{
    printf("Struct Size: %d\n", (int)sizeof(s));
}

int main(int argv, char*argc)
{
    // Ansi C - Chapter 01
    //PrintFahrCelsius();
    
    // Pluralsight
    //TempratureTable(10, 10);
    
    //float c = KelvinToCelsius(274.15f);
    //prHeyintf("Kelvin > Celsius: %.2f\n", c);
    
    //float f = KelvinToFahrenheit(283.15);
    //printf("Kelvin > Fahrenheit: %.2f\n", f);
    
    //c = FahrenheitToCelsius(50);
    //printf("Fahrenheit > Celsius: %.2f\n", c);
    
    //float k = FahrenheitToKelvin(50);
    //printf("Fahrenheit > Kelvin: %.2f\n", k);
    
    //TypeSizes();
    //printf("Macro Test: %d\n", SQUARE(4));
    
    // prints out the struct size in bytes
    //PluralStruct s = {0};
    //PrintStructSize(s);
    
    // prints out the the array depending on the size of the array.
    //PrintArrays();
    
    // functions, arrays and pointers
    int numbers[] = { 7, 5, 4, 2, 3, 9 };
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int* p = numbers; // this points to the first 4 or 8 bytes depending if its on a 32 or 64-bit machine.
    
    printf("array: %d bytes pointer: %d bytes\n", (int)sizeof(numbers), (int)sizeof(p));
    
    int* end = p + size;
    PrintIntegerArray(numbers, numbers + size);
    
    int* smallest = GetSmallestInteger(p, end);
    int* largest = GetLargestInteger(numbers, numbers + size);
    
    if(largest)
    {
        printf("The largest integer in the array are %d\n", *largest); // dereference the pointer
    }
    if(smallest)
    {
        printf("The smallest integer in the array are %d\n", *smallest); // dereference the pointer
    }
    
    
}