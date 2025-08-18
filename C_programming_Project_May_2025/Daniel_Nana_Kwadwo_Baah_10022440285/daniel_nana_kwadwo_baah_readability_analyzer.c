#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0; // start words at 1
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Count letters, words, sentences
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]))
            letters++;
        else if (text[i] == ' ')
            words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    // Calculate averages per 100 words
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // Coleman–Liau Index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print result
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);

    return 0;
}
