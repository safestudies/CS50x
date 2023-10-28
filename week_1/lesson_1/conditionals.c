#include "cs50.h"
#include <stdio.h>

#only an exemplo:

int main(void)
{
    string first = get_string("whats x? ");
    string last = get_string("whats y? ");
    printf("hello, %s %s\n", first, last);
}

if (x < y)
{
    printf("x is less than y\n");
}
else
{
      printf("x is not less than y\n");
}
--------------------
if (x < y)
{
    printf("x is less than y\n");
}
else if (x < y)
{
      printf("x is not less than y\n");
}
else if (x == y) == better code: else ...
{
      printf("x is equal to y\n");
}