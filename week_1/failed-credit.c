#include <cs50.h>
#include <stdio.h>

long get_card(void);
long card_validation(long card);
void print_flag(long card);

int main(void)
{
    long card;

    // Prompt credit number:
    card = get_card();

    // Identify if card is valid
    card = card_validation(card);

    // Print flag:
    print_flag(card);
}

long get_card(void)
{
    long card;

    do
    {
        card = get_long("Card number: ");
    }
    while (card < 0);
    return card;
}

long card_validation(long card)
{
    // Every other digit from right to left starting with the second and *2:
    long dig2, dig4, dig6, dig8, dig10, dig12, dig14, dig16;

    dig2 = ((card % 100) / 10 * 2);
    dig4 = ((card % 10000) / 1000 * 2);
    dig6 = ((card % 1000000) / 100000 * 2);
    dig8 = ((card % 100000000) / 10000000 * 2);
    dig10 = ((card % 10000000000) / 1000000000 * 2);
    dig12 = ((card % 1000000000000) / 100000000000 * 2);
    dig14 = ((card % 100000000000000) / 10000000000000 * 2);
    dig16 = ((card % 10000000000000000) / 1000000000000000 * 2);

    // sum1 - sum of the individual digits of the first section:
    long sum1;

    dig2 = (dig2 % 100 / 10) + (dig2 % 10);
    dig4 = (dig4 % 100 / 10) + (dig4 % 10);
    dig6 = (dig6 % 100 / 10) + (dig6 % 10);
    dig8 = (dig8 % 100 / 10) + (dig8 % 10);
    dig10 = (dig10 % 100 / 10) + (dig10 % 10);
    dig12 = (dig12 % 100 / 10) + (dig12 % 10);
    dig14 = (dig14 % 100 / 10) + (dig14 % 10);
    dig16 = (dig16 % 100 / 10) + (dig16 % 10);

    sum1 = dig2 + dig4 + dig6 + dig8 + dig10 + dig12 + dig14 + dig16;

    // sum2 - The rest of the digits not multiplied:
    long sum2, dig1, dig3, dig5, dig7, dig9, dig11, dig13, dig15;

    dig1 = (card % 10);
    dig3 = ((card % 1000) / 100);
    dig5 = ((card % 100000) / 10000);
    dig7 = ((card % 10000000) / 1000000);
    dig9 = ((card % 1000000000) / 100000000);
    dig11 = ((card % 100000000000) / 10000000000);
    dig13 = ((card % 10000000000000) / 1000000000000);
    dig15 = ((card % 1000000000000000) / 100000000000000);

    sum2 = dig1 + dig3 + dig5 + dig7 + dig9 + dig11 + dig13 + dig15;

    // sum3 - Last digit of sum for validation:
    long sum3;

    sum3 = sum1 + sum2;

    if ((sum3 % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        printf("VALID\n");
        return card;
    }
}

void print_flag(long card)
{
    long tempcard = card;
    // First two digit:
    long firsttwodigits = tempcard;

    // Card lenght:
    int lenght = 0;

    while (tempcard > 0)
    {
        tempcard = tempcard / 10;
        lenght++;
    }

    while (firsttwodigits > 100)
    {
        firsttwodigits = firsttwodigits / 10;
    }

    if ((lenght == 13 || lenght == 16) && (firsttwodigits >= 40 && firsttwodigits <= 49)) //visa:
    {
        printf("VISA\n");
    }
    else if (lenght == 15 && (firsttwodigits == 34 || firsttwodigits == 37)) // American express:
    {
        printf("AMEX\n");
    }
    else if (lenght == 16 && (firsttwodigits >= 51 && firsttwodigits <= 55)) // Mastercard:
    {
        printf("MASTERCARD\n");
    }
}