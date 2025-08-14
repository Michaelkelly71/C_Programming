#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char text[1000];  // Store user input text
    int letters = 0, words = 1, sentences = 0; // Start words at 1 because last word won't have space
    float L, S, index;

    // Prompt for input
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Loop through each character
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++; // Count letters
        } else if (text[i] == ' ') {
            words++; // Count words
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++; // Count sentences
        }
    }

    // Calculate L and S
    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;

    // Coleman–Liau formula
    index = 0.0588 * L - 0.296 * S - 15.8;

    // Round and print result
    int grade = round(index);
    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
