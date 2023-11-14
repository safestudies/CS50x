#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int alphabet_size = 26;

bool argv_validity(string argv[]);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("INVALID INPUT\nUsage: ./substitution key\n");
        return 1;
    }
    else if ((strlen(argv[1]) != alphabet_size) || argv_validity(argv))
    {
        printf("INVALID INPUT\nKey must contain 26 unique characters.\n");
        return 1;
    }

    // get plaintext:
    string plaintext = get_string("plaintext:  ");

    // printf("ciphertext: "); non alphabetical characters unchanged;
    printf("ciphertext: ");

    // printf("%s\n", key);

    string key = argv[1];

    int plain_lenght = strlen(plaintext);

    char ciphertext[plain_lenght + 1];
    int index; // plaintext conversion

    for (int i = 0; i < plain_lenght; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                index = plaintext[i] - 65;
                ciphertext[i] = key[index];
                if (islower(ciphertext[i]))
                {
                    ciphertext[i] -= 32;
                }
            }
            else if (islower(plaintext[i]))
            {
                index = plaintext[i] - 97;
                ciphertext[i] = key[index];
                if (isupper(ciphertext[i]))
                {
                    ciphertext[i] += 32;
                }
            }
            printf("%c", ciphertext[i]);
        }
        else
            printf("%c", plaintext[i]);
    }

    printf("\n");
    return 0;
}

bool argv_validity(string argv[])
{
    int argv_lenght = strlen(argv[1]);

    for (int i = 0; i < argv_lenght; i++)
    {
        argv[1][i] = toupper(argv[1][i]);
    }
    for (int i = 0; i < argv_lenght; i++)
    {
        if (!isalpha(argv[1][i])) // if its not a letter!
        {
            return true;
        }
        for (int j = i + 1; j < argv_lenght; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                return true;
            }
        }
    }
    return false;
}
