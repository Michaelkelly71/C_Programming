#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char text[1000];
    printf("Enter text here: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0, words = 0, sentences = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) letters++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') sentences++;
        if (isspace(text[i])) {
            if (in_word) { words++; in_word = 0; }
        } else {
            in_word = 1;
        }
    }
    if (in_word) words++;

    double L = (100.0 * letters) / words;
    double S = (100.0 * sentences) / words;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1) printf("Before Grade 1\n");
    else if (grade >= 16) printf("Grade 16+\n");
    else printf("Grade %d\n", grade);

    return 0;
}

