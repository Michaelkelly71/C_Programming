#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to count letters in the text
int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the character is an alphabet letter
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count words in the text
int count_words(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Count spaces, as words are separated by spaces
        if (isspace(text[i]))
        {
            count++;
        }
    }
    // Add 1 to account for the last word (after the last space)
    return count + 1;
}

// Function to count sentences in the text
int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Count sentence terminators: '.', '!', '?'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    char text[1000];

    // Prompt user for input
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate L (letters per 100 words) and S (sentences per 100 words)
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    // Apply Coleman–Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round to nearest integer
    int grade = (int)round(index);

    // Output according to specifications
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}
