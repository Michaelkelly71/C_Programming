#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void) {
    char text[2000];
    int letters = 0, words = 0, sentences = 0;
    
    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);
    
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            letters++;
        }
        
        if (isspace(text[i])) {
            words++;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    
    
    words++;
    
    
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    
    
    int coleman_liau_index = round(0.0588 * L - 0.296 * S - 15.8);
    
    
    if (coleman_liau_index < 1) {
        printf("Before Grade 1\n");
    } else if (coleman_liau_index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", coleman_liau_index);
    }
    
    return 0;
}