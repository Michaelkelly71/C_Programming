#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    char text[10000];

    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;

    int letters = 0, words = 0, sentences = 0;
    bool in_word = false;

    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char c = (unsigned char) text[i];

        if (isalpha(c)) letters++;

        if (c == '.' || c == '!' || c == '?') sentences++;

        if (!isspace(c) && !in_word) {  // start of a word
            in_word = true;
            words++;
        } else if (isspace(c)) {
            in_word = false;
        }
    }

    if (words == 0) { puts("Before Grade 1"); return 0; }

    double L = (letters * 100.0) / words;
    double S = (sentences * 100.0) / words;
    int index = (int) lround(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1) {
        puts("Before Grade 1");
    } else if (index >= 16) {
        puts("Grade 16+");
    } else {
        printf("Grade %d\n", index);
    }
    return 0;
}
