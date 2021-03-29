#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;

    // Implementing Coleman-Liau's index
    int res = round(0.0588 * L - 0.296 * S - 15.8);

    if (res < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (res > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", res);
    }

}

int count_letters(string text)
{
    // Function to count the number of letters in a string
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    // Function to count the number of words in a string. Space is the separator.
    // Start at 1 since the last word won't have a space after it.
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }

    return words;
}

int count_sentences(string text)
{
    // Function to count the number of sentences in a string. Only .!? are considered. No minumum sentence length.
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        switch (text[i])
        {
            case '.':
                sentences++;
                break;
            case '!':
                sentences++;
                break;
            case '?':
                sentences++;
                break;
        }
    }

    return sentences;
}