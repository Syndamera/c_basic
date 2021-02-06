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
    return celsius * 9 / 5 + 32;
}

float CelsiusToKelvin(float celsius)
{
    return celsius + 273.15f;
}

void Pluralsight(float celsius)
{
    while(celsius < 100)
    {
        float fahr = CelsiusToFahrenheit(celsius);
        float kelvin = CelsiusToKelvin(celsius);
        printf("%.2f C = %.2f F = %.2f K\n",
               celsius, fahr, kelvin);
        
        celsius = celsius + 10;
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