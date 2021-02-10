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

void MinMax(int* start, int* end, int** smallest, int** largest)
{
    if(start == end)
    {
        *smallest = 0;
        *largest = 0;
    }
    else
    {
        *smallest = *largest = start;
        printf("%d\n", **largest);
        while(++start != end) // make sure we start on the next element in the array by pre inc
        {
            if(*start < **smallest)
            {
                *smallest = start;
            }
            if(*start > **largest)
            {
                *largest = start;
            }
        }
    }
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
    /*int numbers[] = { 7, 5, 4, 2, 3, 9, 12, 55 };
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int* p = numbers; // this points to the first 4 or 8 bytes depending if its on a 32 or 64-bit machine.
    
    printf("array: %d bytes pointer: %d bytes\n", (int)sizeof(numbers), (int)sizeof(p));
    
    int* end = p + size;
    printf("Array Length: %d\n", *end);
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
    
    // c string literals always have a null terminator (0).
    char* string = "Hello W";
    printf("size %d\n", (int)sizeof(string));
    int length = 0;
    for(char* p = string; *p != 0; p++)
    {
        length++;
    }
    printf("length %d\n", length);
    
    printf("Length: %d\n", StringLength("Hello Sailor!"));
    printf("Length: %d\n", StringLength("Hello!"));
    printf("Length: %d\n", StringLength("Hello There"));
    
    // pointers to pointers
    int value = 123;
    int* p1 = &value;
    int** p1p = &p;
    */
    
    int values[] = {5, 2, 4, 2, 6 };
    int sizeValues = sizeof(values) / sizeof(values[0]);
    int* s = 0;
    int* l = 0;
    MinMax(values, values + sizeValues, &s, &l);
    printf("Min = %d Max = %d\n", *s, *l);
    
    
}