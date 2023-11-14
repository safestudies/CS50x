#include "cs50.h"
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    candidate president = get_candidate();

    printf("%s\n%i votes\n", president.name, president.votes);
}

candidate get_candidate(void)
{
    printf("New candidate's profile: \n");

    candidate c;

    c.name = get_string("Name: ");
    c.votes = get_int("Enter number of votes: ");
    return c;
}