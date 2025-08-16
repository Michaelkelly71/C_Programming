#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char text[100];
    printf("Text: \n");
    fgets(text, sizeof(text), stdin);

    int letters = 0, words = 0, sentences = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(i != 0)
        {
            if(text[i] == ' ')
            {
                words++;
                continue;
            }
            else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                sentences++;
                continue;
            }
        }

        if(isalpha(text[i]))
            letters++;
    }

    float L = (float)(letters / words) * 100;
    float S = (float)(sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if(index < 1)
    {
        printf("Before Grade 1.\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("%.2f\n", ceil(index));
    }
    return 0;
}