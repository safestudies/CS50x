#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    // get pyramid's height (1 >= h <= 8):
    int height = get_height();

    // print pyramid:
    print_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Pyramid's Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    int row, column, space;

    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}