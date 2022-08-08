#include <stdlib.h>
#include <stdio.h>
#include "my_alg.h"

float average_ii(int a, int b)
{
    return ((float)(a+b)) / 2;
}

float average_ff(float a, float b)
{
    return (a+b)/2;
}

float average(int* arr, int size)
{
    int sum;
    for (size_t i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return ((float)(sum))/size;
}

