#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

float Sqr(int a)
{
    // a = input number;
    // b = potential square root  
    // a = b * b
    float b = 1;
    while(b * b < a) // a = 16 != b = 4 * 4
    {
        b++;
    }
    
    // we found the right integer value.
    // if b * b > a then add with a precision number
    
    if(b * b > a)
    {
        b--; // remove 1 and start adding precision
        float precision = 0.0001;
        while(b * b < a)
        {
            b = b + precision;
        }
    }
    return b;
}

int Pow(int base, int exponent)
{
    int number = 1;
    for(int i = 1; i <= exponent; i++)
    {
        number = base * number;
    }
    return number;
}

void MinMax(int* start, int* end, int** smallest, int** largest) // smallest, largest are out parameters
{
    if(start == end)
    {
        *smallest = 0; // setting the out parameters to 0
        *largest = 0;
    }
    else
    {
        *smallest = *largest = start; // assumes that element 0 is both the smallest and largest number
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
    
    // # POINTERS TO POINTERS #
    int value = 123;
    int* p1 = &value;
    int** p1p = &p;
    */
    
    // passing the adress of pointers to pointers in a function - use debugger to see values of pointers in memory.
    /*int* s = 0;
    int* l = 0;
    int values[] = {5, 2, 4, 6, 9 };
    int sizeValues = sizeof(values) / sizeof(values[0]);
    
    MinMax(values, values + sizeValues, &s, &l);
    printf("Min = %d Max = %d\n", *s, *l);*/
    
    // memory management - use debugger, this code won't run correctly.
    /*int* p = (int*)malloc(4); // allocating memory on the Heap
    if(!p)
    {
        return 1; // no heap memory avaible
    }
    *p = 42;
    free(p);
    void* frame = malloc(514);
    free(frame);
    char* message = (char*) malloc(200);
    message = "testing a message";
    free(message);*/
    
    // input and output - formatting with printf
    /*printf("%I64d\n", 111222333444);
    printf("0x%I64X\n", 111222333444);
    
    printf("%10.2f\n", 123.456); // rounds up to fit the two decimal restriction
    printf("%10d\n", 456); // right align numbers, use (-) infront of the 10 to left align the numbers
    
    char* message = "Hi, How are you?";
    int charsize = 5;
    printf("%.*s\n", charsize, message);*/
    
    // strings, security and scanf
    /*char* font = "Myriad Pro";
    int size = 32;
    char* message = "Hello World";
    
    char buffer[256];
    //sprintf does not take a sizeof
    sprintf_s(buffer, sizeof(buffer), "<html><body><p style='font-family:%s;font-size:%dpx'>%s</p></body></html>",
              font, size, message);
    printf("%s\n", buffer);
    
    //int a, b, c;
    //scanf("%d %d %d", &a, &b, &c); // we can easily overflow scanf
    //printf("%d %d %d", a, b, c);
    
    unsigned char input[10];
    scanf_s("%9s", &input, sizeof(input)); // (9) truncates the input
    printf("%s", input);*/
    
    // files
    /*FILE* f = 0;
    errno_t result = fopen_s(&f, "W:\\c_basic\\assets\\message.txt", "w"); // if it does not exist it creates one.
    
    if(result != 0)
    {
        char buffer[100];
        strerror_s(buffer, sizeof(buffer), result);
        
        printf("%s (%d)\n", buffer, result);
        return result;
    }
    
    fprintf_s(f, "Hello file\n");
    fclose(f);*/
    
    // strings manipulation, char manipulation
    char* msg = "Hello, this is a message! I contain: 1, 2, 3\n";
    printf(msg);
    
    /*for(char* p = msg; *p; p++)
    {
        char c = *p;
        printf("%c\t", c);
        
        if(isalnum(c)) printf("isalnum ");
        if(isalpha(c)) printf("isalpha ");
        if(islower(c)) printf("islower ");
        if(isupper(c)) printf("isupper ");
        if(isdigit(c)) printf("isdigit ");
        if(isxdigit(c)) printf("isxdigit ");
        if(iscntrl(c)) printf("iscntrl ");
        if(isgraph(c)) printf("isgraph ");
        if(isspace(c)) printf("isspace ");
        if(isblank(c)) printf("isblank ");
        if(isprint(c)) printf("isprint ");
        if(ispunct(c)) printf("ispunct ");
        
        printf("\n");
    }*/
    
    for(char* p = msg; *p; p++)
    {
        if(isupper(*p))
            *p = (char)tolower(*p);
        else if(islower(*p))
            *p = (char)toupper(*p);
    }
    printf(msg);
    
    double d = atof("123.456"); // ascii to float (wtof = wide char)
    int i = atoi("1234"); // ascii to int
    printf("%.3f %d\n", d, i);
    
    char* numbers = "12 0x123 101"; // decimal, hex, binary
    char* next = numbers;
    int decimal = strtol(next, &next, 10); // string to long
    int hex = strtol(next, &next, 0); // detect number system but if missed it will be decimal
    int binary = strtol(next, &next, 2);
    printf("%d %d %d\n", decimal, hex, binary);
    
    msg = "Hello";
    printf("size: %d\n", (int)strlen(msg));
    printf("Apples %d\n", strcmp(msg, "Apples"));
    printf("Oranges %d\n", strcmp(msg, "Oranges"));
    printf("Hello %d\n", strcmp(msg, "Hello"));
    
    int base = 2;
    int exp = 8;
    int Result = Pow(base, exp);
    printf("Power of %d^%d equals %d\n", base, exp, Result);
    
    float root = Sqr(12);
    printf("SQR: %.4f\n", root);
    float int_max = 21474483547;
    printf("INT MAX = %f\n", int_max);
    float root1 = Sqr(3448354);
    printf("SQR: %.4f\n", root1);
    
    return 0;
}