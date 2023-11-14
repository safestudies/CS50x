#include "cs50.h"
#include <stdio.h>
#include <string.h>

const int n = 2;

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[n];

    people[0].name = "Alfred";
    people[0].number = "+1-123-456";

    people[1].name = "Bruce";
    people[1].number = "+1-321-654";

    string s = get_string("Name: ");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(people[i].name, s) == 0)
        {
            printf("found\n%s\n%s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 404;
}