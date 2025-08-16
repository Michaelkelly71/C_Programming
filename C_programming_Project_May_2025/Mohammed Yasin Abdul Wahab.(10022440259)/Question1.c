#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get input from user
    char text[1000];  // buffer size (can be adjusted if needed)
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0;
    int words = 1;      // start at 1 because words = spaces + 1
    int sentences = 0;

    // Loop through each character in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate L and S
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Output results
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
