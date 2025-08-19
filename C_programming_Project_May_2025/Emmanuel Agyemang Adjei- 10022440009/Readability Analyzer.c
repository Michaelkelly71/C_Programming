#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char text[1000];
    int letters = 0, words = 0, sentences = 0;
    int in_word = 0; 

    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    
    text[strcspn(text, "\n")] = '\0';

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
        else if (isspace(text[i]))
        {
            in_word = 0;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
            in_word = 0;
        }
        else
        {
            
            if (in_word) {
                
            } else {
                in_word = 0;
            }
        }
    }

    
    if (words == 0) {
        printf("Before Grade 1\n");
        return 0;
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