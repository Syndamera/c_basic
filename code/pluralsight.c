#include <stdio.h>

typedef unsigned char byte;

// Macro
#define SQUARE(x) Multiply(x, x)

int Multiply(int a, int b)
{
    return a * b;
}

float CelsiusToFahrenheit(float celsius)
{
    return celsius * (9 / 5) + 32;
}

float CelsiusToKelvin(float celsius)
{
    return celsius + 273.15f;
}

float KelvinToCelsius(float kelvin)
{
    return kelvin - 273.15f;
}

// f - 32 / 9 / 5
float FahrenheitToCelsius(float fahr)
{
    return fahr - 32 / (9 / 5);
}

void TempratureTable(float celsius, int step)
{
    while(celsius <= 40)
    {
        float fahr = CelsiusToFahrenheit(celsius);
        float kelvin = CelsiusToKelvin(celsius);
        printf("%.0fc = %.2ff = %.2fk\n",
               celsius, fahr, kelvin);
        
        celsius = celsius + step;
    }
}

// no return type so is not declared in the .h file, why does this work?
void TypeSizes()
{
    printf("byte: %u bytes\n", (int)sizeof(byte));
    printf("char: %d bytes\n", (int)sizeof(char));
    printf("int: %d bytes\n", (int)sizeof(int));
    printf("float: %d bytes\n", (int)sizeof(float));
    printf("double: %d bytes\n", (int)sizeof(double));
}