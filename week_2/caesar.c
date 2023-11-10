#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool argv_validity(string argv[]);

int main(int argc, string argv[])
{
    if (argc != 2 || argv_validity(argv))
    {
        printf("INVALID INPUT\nUsage: ./caesar key\n");
        return 1;
    }

    // accept from command-line a non-negative integer 'k;
    // if inputted a non valid 'k', printf("INVALID INPUT\nUsage: ./caesar key"); and return 1;

    int k = atoi(argv[1]);

    printf("%i\n", k);

    // get plaintext:
    string plaintext = get_string("plaintext:  ");

    // printf("ciphertext: "); non alphabetical characters unchanged;
    printf("ciphertext: ");

    // ASCII: A-Z = 65-90; a-z = 97-122; Must loop in those ranges.

    // first transform everything in ascii numbers:
    int plain_lenght = strlen(plaintext);

    for (int i = 0; i < plain_lenght; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int decimal_plain = plaintext[i];

            int decimal_cipher = decimal_plain + k;

            if (islower(plaintext[i]) && decimal_cipher > 122) // for a-z
            {
                do
                {
                int diff = decimal_cipher - 122;
                decimal_cipher = 96 + diff;
                }
                while (decimal_cipher > 122);
            }
            else if (isupper(decimal_cipher) && decimal_cipher > 90) // for A-Z
            {
                do
                {
                int diff = decimal_cipher - 90;
                decimal_cipher = 64 + diff;
                }
                while (decimal_cipher > 90);
            }

            printf("%c", decimal_cipher);
        }
        else
            printf("%c", plaintext[i]);
    }

    // ciphertext = plaintext + key

    printf("\n");
    return 0;
}

bool argv_validity(string argv[])
{
    int argv_lenght = strlen(argv[1]);

    for (int i = 0; i < argv_lenght; i++)
    {
        if (!isdigit(argv[1][i])) // if its not a digit!
        {
            return true;
        }
    }
    return false;
}
