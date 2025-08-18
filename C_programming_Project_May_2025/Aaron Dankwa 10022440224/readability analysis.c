#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    char block_of_text[1000];
    double letters = 0, words = 1, sentences = 0;

    printf("Enter a block of English text:\n");
    fgets(block_of_text, sizeof(block_of_text), stdin);

    for (int i = 0; block_of_text[i] != '\0'; i++) {
        if (isalpha(block_of_text[i])) {
            letters++;
        } else if (block_of_text[i] == ' ') {
            words++;
        } else if (block_of_text[i] == '.' || block_of_text[i] == '!' || block_of_text[i] == '?') {
            sentences++;
        }
    }

    
    double L = (letters / words) * 100;
    double S = (sentences / words) * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
