// 30-10-23
#include "cs50.h"
#include <stdio.h>

double get_startsize(void);
double get_endsize(double s);
// void print_years(int years)

int main(void)
{
    // TODO: Prompt for start size
    // s = start population
    double s = get_startsize();

    // TODO: Prompt for end size
    // e = end population
    double e = get_endsize(s);

    // TODO: Calculate number of years until we reach threshold
    // y = number of years | n = next years population
    int y = 0;
    double n = s;

    while (n < e)
    {
        n = n + (n / 3.0) - (n / 4.0);
        y++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", y);
}

double get_startsize(void)
{
    double s;
    do
    {
        s = get_double("start size: ");
    }
    while (s < 9.0);
    return s;
}

double get_endsize(double s)
{
    double e;
    do
    {
        e = get_double("end size: ");
    }
    while (e < s);
    return e;
}