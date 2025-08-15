#include <stdio.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0;
    double L, S, index;
    int grade;

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Count letters, words, sentences
    for (int i = 0; text[i] != '\0'; i++) {
        // Check if it's an uppercase letter
        if (text[i] >= 'A' && text[i] <= 'Z') {
            letters++;
        }
        // Check if it's a lowercase letter
        else if (text[i] >= 'a' && text[i] <= 'z') {
            letters++;
        }
        else if (text[i] == ' ') {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    // Calculate L and S
    L = (letters * 100.0) / words;
    S = (sentences * 100.0) / words;

    // Coleman–Liau formula
    index = 0.0588 * L - 0.296 * S - 15.8;

    // Manual rounding without math.h
    if (index >= 0)
        grade = (int)(index + 0.5);
    else
        grade = (int)(index - 0.5);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
