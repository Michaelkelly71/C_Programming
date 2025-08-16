#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {
    char text[1000];
    int letters = 0, words = 0, sentences = 0;
    
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    
    for (int i = 0; text[i] != '\0'; i++) {

        if (isalpha(text[i])) {
            letters++;
        }
        
        if (isspace(text[i]) && (i > 0 && !isspace(text[i-1]))) {
            words++;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    
    
    if (!isspace(text[0]) && letters > 0) {
        words++;
    }
    
    
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    

    float index = 0.0588 * L - 0.296 * S - 15.8;
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