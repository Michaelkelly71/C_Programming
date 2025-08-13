#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char text[1000]; 
    int letters = 0, words = 1, sentences = 0; 

    printf("Enter a paragraph:\n");
    fgets(text, sizeof(text), stdin); 

    
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++;
        } else if (text[i] == ' ') {
            words++;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100; 
    float index = 0.0588 * L - 0.296 * S - 15.8;

    printf("\nLetters: %d", letters);
    printf("\nWords: %d", words);
    printf("\nSentences: %d", sentences);

    
    int grade = round(index);

    printf("\nGrade Level: ");
    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
