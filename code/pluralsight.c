#include <stdio.h>

typedef unsigned char byte;

// Macro
#define SQUARE(x) Multiply(x, x)

int Multiply(int a, int b)
{
    return a * b;
}

// f = c * (9 / 5) + 32
// f - 32 = c * (9 / 5) + 32 - 32
// f - 32 = c * (9 / 5)
// (f -32) / (9 / 5) = c * (9 / 5) / (9 / 5)
// (f -32) / (9 / 5) = c
// c = (f - 32) / (9 / 5)
float CelsiusToFahrenheit(float celsius)
{
    return celsius * 1.8f + 32;
}

float CelsiusToKelvin(float celsius)
{
    return celsius + 273.15f;
}

float KelvinToCelsius(float kelvin)
{
    return kelvin - 273.15f;
}

// k = (f - 32) / (9 / 5) + 273.15
// k - 273.15 = (f - 32) / (9 / 5) + 273.15 - 273.15 
// k - 273.15 = (f - 32) / (9 / 5)
// k - 273.15 * (9 / 5) = (f - 32) / (9 / 5) * (9 / 5)
// k - 273.15 * (9 / 5) = 1 * (f - 32)
// k - 273.15 * (9 / 5) = f - 32
// k - 273.15 * (9 / 5) + 32 = f - 32 + 32
// (k - 273.15) * (9 / 5) + 32 = f
// f = (k - 273.15) * (9 / 5) + 32
// f = (9 / 5 * k) - (9 / 5 * 273.15) + 32
// f = (9 / 5 * k) - (9 * 273.15 / 5) + 32
// f = (9 / 5 * k) - 491.67 + 32
// f = (9 / 5 * k) - 459.64

float KelvinToFahrenheit(float kelvin)
{
    return (1.8f * kelvin) - 459.64;
}

// f = c * (9 / 5) + 32
// k = (f - 32) / (9 / 5) + 273.15
float FahrenheitToKelvin(float fahr)
{
    return (fahr - 32) / 1.8f + 273.15;
}

// c = f - 32 / 9 / 5
float FahrenheitToCelsius(float fahr)
{
    return (fahr - 32) / 1.8f;
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
    printf("short: %d bytes\n", (int)sizeof(short));
    printf("int: %d bytes\n", (int)sizeof(int));
    printf("float: %d bytes\n", (int)sizeof(float));
    printf("double: %d bytes\n", (int)sizeof(double));
}
