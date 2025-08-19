#include <stdio.h>

int main() {
    char text[1000];
    int letters = 0;
    int words = 1;       
    int sentences = 0;
    double L, S, index;
    int grade;

    
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Go through each character in the text
    for (int i = 0; text[i] != '\0'; i++) {
        
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        }
        // Count spaces to get words
        else if (text[i] == ' ') {
            words++;
        }
        
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    
    L = (letters * 100.0) / words;
    S = (sentences * 100.0) / words;

    // Coleman–Liau formula
    index = 0.0588 * L - 0.296 * S - 15.8;

    // round the number to the nearest whole number
    if (index >= 0) {
        grade = (int)(index + 0.5);
    } else {
        grade = (int)(index - 0.5);
    }

    
    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}