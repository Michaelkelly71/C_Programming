#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char text[1000];
    int letters = 0, words = 1, sentences = 0; 

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        
        if (isspace(text[i]))
        {
            words++;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

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