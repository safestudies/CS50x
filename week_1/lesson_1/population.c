// Comparison between my code and chatGPT:

//My Version:

//#include <cs50.h>
//#include <stdio.h>
//
//int get_startsize(void);
//int get_endsize(int start);
//void print_years(int years)
//
//int main(void)
//{
//    // TODO: Prompt for start size
//    int s = get_startsize();
//
//    // TODO: Prompt for end size
//    int e = get_endsize(s);
//
//    // TODO: Calculate number of years until we reach threshold
//    // x == yearly growth | y == number of years
//    int x = s + (s / 3) - (s / 4);
//    int y = e / x;
//
//    // TODO: Print number of years
//    printf("Years: %d\n", y );
//}
//
//
//    int get_startsize(void)
//{
//    int s;
//    do
//    {
//        s = get_int("start size: ");
//    }
//    while (s < 9);
//    return s;
//}
//
//    int get_endsize(int start)
//{
//    int e;
//    do
//    {
//        e = get_int("end size: ");
//    }
//    while (e < start);
//    return e;
//}

//ChatGPT's Version:

#include "cs50.h"
#include <stdio.h>

#define GROWTH_RATE 3
#define DECAY_RATE 4

int getPopulationSize(const char *prompt, int minSize);
int calculateYears(int startSize, int endSize);

int main(void)
{
    int startSize = getPopulationSize("Enter start size: ", 9);
    int endSize = getPopulationSize("Enter end size (must be greater than start size): ", startSize);

    int years = calculateYears(startSize, endSize);

    printf("Years to reach end size: %d\n", years);
}

int getPopulationSize(const char *prompt, int minSize)
{
    int size;
    do
    {
        size = get_int("%s", prompt);
    }
    while (size < minSize);
    return size;
}

int calculateYears(int startSize, int endSize)
{
    int yearlyGrowth = startSize + (startSize / GROWTH_RATE) - (startSize / DECAY_RATE);
    return endSize / yearlyGrowth;
}