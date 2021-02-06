#include <stdio.h>

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