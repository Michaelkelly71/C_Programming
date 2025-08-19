#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char text[5000];

    printf("Text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    int letters = 0, words = 0, sentences = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isalpha(c)) {
            letters++;
        }

        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }

        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    if (words == 0) {
        puts("Before Grade 1");
        return 0;
    }

    double L = (double)letters / words * 100;
    double S = (double)sentences / words * 100;
    int grade = (int)round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1) {
        puts("Before Grade 1");
    } else if (grade >= 16) {
        puts("Grade 16+");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}