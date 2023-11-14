#include "cs50.h"
#include <stdio.h>

const int n = 2;

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    candidate candidates[n];

    for (int i = 0; i < n; i++)
    {
        candidates[i] = get_candidate();
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%s\n%i votes\n\n", candidates[i].name, candidates[i].votes);
    }
}

candidate get_candidate(void)
{
    printf("New candidate's profile: \n");

    candidate c;

    c.name = get_string("Name: ");
    c.votes = get_int("Enter number of votes: ");
    printf("\n");
    return c;
}