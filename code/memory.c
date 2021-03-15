#include <stdio.h>

int HalfAdder(int a, int b)
{
    int sum = 0;
    int carry = 0;
    while(b != 0)
    {
        sum = a^b;
        carry = (a&b) << 1;
        a = sum;
        b = carry;
    }
    return sum;
}

void Memory()
{
    int a = 15;
    int b = 6;
    printf("%d\n", HalfAdder(a, b));
}