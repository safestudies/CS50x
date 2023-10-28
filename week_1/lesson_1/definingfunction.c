#include <stdio.h>
#include "cs50.h"

 // Copied the variables definition to the top and added ";" to tell "c" their definition is below.
int get_size(void);
void print_grid(int size);

int main(void)
{
    //Get size of grid
    int n = get_size();

    // Print grid of bricks
    print_grid(n);
}


// First variable gets only positive numbers from user and returns value (n) to the next lines of code (Print_grid).
int get_size(void)
{
    int n;
    do
    {
        n = get_int("size: ");
    }
    while (n < 1);
    return n;
}

// Secong variable only prints the grid from the value it gets from (n) in the first variable (get_size).
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}