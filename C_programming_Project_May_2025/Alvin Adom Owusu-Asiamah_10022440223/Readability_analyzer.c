#include <stdio.h>

int main() { 
    char text[1000];
    int letters = 0, words = 1, sentences = 0;
    
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    for (int i = 0; text[i] != '\0'; i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        }
        else if (text[i] == ' ' && ((text[i+1] >= 'A' && text[i+1] <= 'Z') ||(text[i+1] >= 'a' && text[i+1] <= 'z'))) 
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    
    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    int index = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5);
    
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }
    
    return 0;
}