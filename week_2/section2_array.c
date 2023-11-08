#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get array's lenght = n:
    int n;
    do
    {
        n = get_int("lenght: ");
    }
    while (n < 1);

    // Declare the array:
    int array[n];

    // Set the first value:
    array[0] = 1;
    printf("%i\n", array[0]);

    for (int i = 1; i < n; i++)
    {
        // Set current value x2 the previous:
        array[i] = 2 * array[i - 1];

        // Print the array:
        printf("%i\n", array[i]);
    }
}
