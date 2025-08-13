#include <stdio.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0;
    int i = 0;
    
    printf("Text: ");
    gets(text);
    
    while(text[i] != '\0') {
        // Count letters (A-Z, a-z)
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        }
        // Count words (separated by space)
        if(text[i] == ' ') {
            words++;
        }
        // Count sentences (., !, ?)
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
        i++;
    }
    
    // Calculate L and S
    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    
    // Calculate index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)(index + 0.5); // Simple rounding
    
    // Display result
    if(grade < 1) {
        printf("Before Grade 1");
    }
    else if(grade >= 16) {
        printf("Grade 16+");
    }
    else {
        printf("Grade %d", grade);
    }
    
    return 0;
}