#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);

    // printf("letters: %i\n", letters);

    int words = count_words(text);

    // printf("words: %i\n", words);

    int sentences = count_sentences(text);

    // printf("sentences: %i\n", sentences);

    int L = ((float) letters / words) * 100;
    int S = ((float) sentences / words) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    if (index > 1 && index < 17)
    {
        printf("Grade %i\n", (int) index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
        printf("Grade 16+\n");
}

int count_sentences(string text)
{
    int sentences = 0;
    int i = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

int count_words(string text) // (How to ignore strings of numbers and not count them as words??)
{
    int words = 0;
    int i = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_letters(string text)
{
    int total_letters = strlen(text);
    int symbols = 0;
    int i = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (ispunct(text[i]) || isspace(text[i]) || isdigit(text[i]))
        {
            symbols++;
        }
    }

    int letters = total_letters - symbols;
    return letters;
}
