#include <cs50.h>
#include <math.h> // for pow(10, x)
#include <stdio.h>

    // submitted version was cleaned from all the '//'

long get_card(void);
int card_validation(long card);
int evendigitsproduct(int last_digit);
int cardlenght(long card);

bool valid_amex(long card, int lenght);
bool valid_master(long card, int lenght);
bool valid_visa(long card, int lenght);

// void print_flag(long card, int lenght);

int main(void)
{
    long card;
    int checksum;
    int lenght;
    bool amex;
    bool master;
    bool visa;

    // Prompt credit number:
    card = get_card();

    // Identify if card is valid
    checksum = card_validation(card);

    lenght = cardlenght(card);

    // printf("%i\n", lenght);

    amex = valid_amex(card, lenght);

    master = valid_master(card, lenght);

    visa = valid_visa(card, lenght);

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    // Print flag:
    // print_flag(card, lenght);
}

bool valid_amex(long card, int lenght)
{
    int firsttwodigits = card / pow(10, 13);

    if ((lenght == 15) && (firsttwodigits == 34 || firsttwodigits == 37))
    {
        return true;
    }
    return false;
}

bool valid_master(long card, int lenght)
{
    int firsttwodigits = card / pow(10, 14);

    if ((lenght == 16) && (firsttwodigits > 50 && firsttwodigits < 56))
    {
        return true;
    }
    return false;
}

bool valid_visa(long card, int lenght)
{
    if (lenght == 13)
    {
        int firstdigit = card / pow(10, 12);

        if (firstdigit == 4)
        {
            return true;
        }
    }
    else if (lenght == 16)
    {
        int firstdigit = card / pow(10, 15);

        if (firstdigit == 4)
        {
            return true;
        }
    }
    return false;
}

    // didnt work :(

// void print_flag(long card, int lenght)
//{
//
//     if (lenght == 15) // American express:
//     {
//         int amex = card / pow(10, 13);
//
//         if(amex == 34 || amex == 37)
//         {
//         printf("AMEX\n");
//         return;
//         }
//     }
//     else if (lenght == 13 || lenght == 16) //visa:
//     {
//         int visa = card;
//
//         if((visa / pow(10, 11)) >= 40 && (visa / pow(10, 11)) <= 49)
//         {
//         printf("VISA\n");
//         return;
//         }
//         else if((visa / pow(10, 14)) >= 40 && (visa / pow(10, 14)) <= 49)
//         {
//         printf("VISA\n");
//         return;
//         }
//     }
//     else if (lenght == 16) // Mastercard:
//     {
//         int master = card / pow(10, 14);
//
//         if(master >= 51 && master <= 55)
//         {
//         printf("MASTERCARD\n");
//         return;
//         }
//     }
//     printf("INVALI\n");
// }

int cardlenght(long card)
{
    int lenght = 0;

    while (card > 0)
    {
        lenght++;
        card /= 10;
    }
    return lenght;
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

int card_validation(long card)
{
    int checksum = 0;
    bool evendigits = false;
    int last_digit;
    int productsum;

    while (card > 0)
    {
        if (evendigits == true) // if even number from left to right, *2, sum digits and add to the sum:
        {
            last_digit = card % 10;
            productsum = evendigitsproduct(last_digit); // last_digit * 2 and sum of their digits:
            checksum = checksum + productsum;
        }
        else // if odd number from lesft to write, sumply add to the sum:
        {
            last_digit = card % 10;
            checksum = checksum + last_digit;
        }
        evendigits = !evendigits; // when odd number from left to right, change bool and skip to next one:
        card /= 10;
    }
    return checksum;
}

int evendigitsproduct(int last_digit)
{
    int product = last_digit * 2;
    int last_digitproduct; // Each individual digit of the product.
    int productsum = 0;

    while (product > 0)
    {
        last_digitproduct = product % 10;
        productsum = productsum + last_digitproduct;
        product /= 10;
    }
    return productsum;
}