#include <stdio.h>
#include <math.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0;

    printf("Text: ");
    fgets(text, 1000, stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            letters++;
        if (c == ' ')
            words++;
        if (c == '.' || c == '!' || c == '?')
            sentences++;
    }

    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    int grade = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5); // rounding

    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);

    return 0;
}