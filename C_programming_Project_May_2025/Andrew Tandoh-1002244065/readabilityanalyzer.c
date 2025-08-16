#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void) {
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline

    int letters = 0, words = 0, sentences = 0;
    int in_word = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
        if (text[i] == ' ') {
            if (in_word) in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    float L, S;
    if (words > 0) {
        L = (float)letters / words * 100;
        S = (float)sentences / words * 100;
    } else {
        L = S = 0;
    }

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)round(index);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}