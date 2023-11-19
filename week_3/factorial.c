#include "cs50.h"
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n = get_int("Type a number: ");
    
    printf("%i\n", factorial(n));
}

int factorial(int n)
{
    // First define the "base case";
    if (n == 1)
    {
        return 1;
    }

    // Call factorial of n - 1 and so on until it get to 1!;
    n = n * factorial(n - 1);
    return n;

}