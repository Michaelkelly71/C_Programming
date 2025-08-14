// Question 1- readability analyzer 

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char text[10000];

    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;

    long letters = 0, words = 0, sentences = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isalpha((unsigned char)c)) {
            letters++;
        }

        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }

        if (c != ' ' && c != '\n' && !in_word) {
            in_word = 1;
            words++;
        } else if (c == ' ' || c == '\n') {
            in_word = 0;
        }
    }

    if (words == 0) {
        printf("Before Grade 1\n");
        return 0;
    }

    double L = (letters * 100.0) / words;
    double S = (sentences * 100.0) / words;
    int index = (int)lround(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }
    return 0;
}