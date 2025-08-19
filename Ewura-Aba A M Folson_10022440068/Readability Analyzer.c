#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void){
    char text[1000];
    int letters = 0, words = 0, sentences = 0;
    int in_word = 0; // flag to track if were inside a word

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

     for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            letters++;
        }
        
         // Count words by detecting transitions from space to non-space
        if (isspace(text[i])) {
            if (in_word){
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
        
        // Count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    
   // Count the last word if the text doesn't end with a space
    if (in_word) {
        words++;
    }

    // Avoid division by zero
    if (words == 0) {
        printf("Before Grade 1\n");
        return 0;
    }
    
    // Calculate L and S
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    
    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // Output result
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }


    return 0;
}