#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("word: ");

    int word_lenght = strlen(word);

    printf("%i\n", word_lenght);

    for (int i = 0; i < word_lenght; i++)
    {
        if (word[i] < word[i - 1])
        {
            printf("No\n");
            return 0;
        }
        else
        printf("%c ", word[i]);
    }
    printf("\nYes\n");
    return 0;
}
