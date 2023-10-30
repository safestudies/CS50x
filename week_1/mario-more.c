#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    // Get pyramid's height (1 >= h <= 8):
    int height = get_height();

    // Print pyramid:
    print_pyramid(height);
}

int get_height(void)
{
    int height;

    do
    {
        height = get_int("Pyramid's height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    int row, rightcolumn, leftcolumn, space;

    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (rightcolumn = 0; rightcolumn <= row; rightcolumn++)
        {
            printf("#");
        }

        printf("  ");

        for (leftcolumn = 1; leftcolumn <= rightcolumn; leftcolumn++)
        {
            printf("#");
        }
        printf("\n");
    }
}