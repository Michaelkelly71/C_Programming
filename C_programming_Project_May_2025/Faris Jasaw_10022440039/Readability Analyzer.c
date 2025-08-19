#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char text[10000];


    int letters = 0;
    int sentences = 0;
    int words = 0;
    int in_word = 0; 

   
    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin)) {
        return 0;
    }


    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

     
        if (isalpha((unsigned char)c)) {
            letters++;
        }

       
        if (c != ' ' && c != '\n' && c != '\t' && !in_word) {
            words++;
            in_word = 1;
        } else if (c == ' ') {
            in_word = 0;
        }

        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }
    }

    if (words == 0) {
       
        printf("Before Grade 1\n");
        return 0;
    }


    double L = (letters * 100.0) / words;
    double S = (sentences * 100.0) / words;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)lround(index);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
