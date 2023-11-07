#include <stdio.h>
#include "cs50.h"

float average(int tests, int scores[]);

int main(void)
{
    // Getting scores from x tests:
    const int tests = 3;
    int scores[tests];

    for (int i = 0; i < tests; i++)
    {
        scores[i] = get_int("test score: ");
    }

    for (int i = 0; i < tests; i++)
    {
        printf("score %i: ", i + 1);
        printf("%i\n", scores[i]);
    }

    printf("Average: %.2f\n", average(tests, scores));
}

float average(int tests, int scores[])
{
    int sum = 0;

    for (int i = 0; i < tests; i++)
    {
        sum += scores[i];
    }
    return (float) sum / tests;
}