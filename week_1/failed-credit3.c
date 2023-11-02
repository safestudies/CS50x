#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Card number:
    long card;

    do
    {
        card = get_long("Card number: ");
    }
    while (card < 0);

    // Every other digit from right to left starting with the second and *2:
    int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8;

    dig1 = ((card % 100) / 10 * 2);
    dig2 = ((card % 10000) / 1000 * 2);
    dig3 = ((card % 1000000) / 100000 * 2);
    dig4 = ((card % 100000000) / 10000000 * 2);
    dig5 = ((card % 10000000000) / 1000000000 * 2);
    dig6 = ((card % 1000000000000) / 100000000000 * 2);
    dig7 = ((card % 100000000000000) / 10000000000000 * 2);
    dig8 = ((card % 10000000000000000) / 1000000000000000 * 2);

    // sum1 - sum of the individual digits of the first section:

    dig1 = (dig1 % 100 / 10) + (dig1 % 10);
    dig2 = (dig2 % 100 / 10) + (dig2 % 10);
    dig3 = (dig3 % 100 / 10) + (dig3 % 10);
    dig4 = (dig4 % 100 / 10) + (dig4 % 10);
    dig5 = (dig5 % 100 / 10) + (dig5 % 10);
    dig6 = (dig6 % 100 / 10) + (dig6 % 10);
    dig7 = (dig7 % 100 / 10) + (dig6 % 10);
    dig8 = (dig8 % 100 / 10) + (dig7 % 10);

    int sum1 = dig1 + dig2 + dig3 + dig4 + dig5 + dig6 + dig7 + dig8;

    // sum2 - The rest of the digits not multiplied:
    int dig9, dig10, dig11, dig12, dig13, dig14, dig15, dig16;

    dig9 = (card % 10);
    dig10 = ((card % 1000) / 100);
    dig11 = ((card % 100000) / 10000);
    dig12 = ((card % 10000000) / 1000000);
    dig13 = ((card % 1000000000) / 100000000);
    dig14 = ((card % 100000000000) / 10000000000);
    dig15 = ((card % 10000000000000) / 1000000000000);
    dig16 = ((card % 1000000000000000) / 100000000000000);

    int sum2 = dig9 + dig10 + dig11 + dig12 + dig13 + dig14 + dig15 + dig16;

    // sum3 - Last digit of sum for validation:
    int sum3 = sum1 + sum2;

    if ((sum3 % 10) != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    // Card lenght:
    int lenght = 0;

    while (card > 0)
    {
        card = card / 10;
        lenght++;
    }

    long visa = card;
    long amex = card;
    long master = card;

    //visa:
    while (visa >= 10)
    {
        visa /= 10; // card = card / 10;
    }
    if (visa == 4 && (lenght == 13 || lenght == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }

    // American express (amex):
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (lenght == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    // Mastercard:
    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (lenght == 16 && (master == 51 || master == 52 || master == 53 || master ==54 || master == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    printf("%s\n", "INVALID");
    return 0;
}