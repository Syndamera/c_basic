// Ansi C - Chapter 1

#include <stdio.h>

static void PrintFahrCelsius()
{
    // formula: c = (5/9)(f-32)
    int f = 0;
    int c = 0;
    int lower = 0;
    int upper = 300;
    int step = 20;
    
    while(f <= upper)
    {
        c = 5 * (f-32) / 9;
        printf("%d\t%d\n", f, c);
        f = f + step;
    }
}