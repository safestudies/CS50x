#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

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

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
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
    int words = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
