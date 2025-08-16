#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main() {
    char text[1000];
    int letters = 0, words = 0, sentences = 0;
    
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    int length = strlen(text);
    
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
        
        if (text[i] == ' ' && (i > 0 && text[i-1] != ' ')) {
            words++;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    
    if (length > 0 && text[length-1] != ' ') {
        words++;
    }
    
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }
    
    return 0;
}