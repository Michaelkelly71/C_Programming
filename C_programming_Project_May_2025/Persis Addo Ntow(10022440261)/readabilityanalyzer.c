#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void) {
    char input_text[1000];
    
    
    printf("Text: ");
    fgets(input_text, sizeof(input_text), stdin);
    
    int letter_count = 0;
    int word_count = 1;  
    int sentence_count = 0;
    
    for (int i = 0; input_text[i] != '\0'; i++) {
        char current_char = input_text[i];
        
        if (isalpha(current_char)) {
            letter_count++;
        }
        
        if (current_char == ' ') {
            word_count++;
        }
        
        if (current_char == '.' || current_char == '!' || current_char == '?') {
            sentence_count++;
        }
    }
    
    float average_letters = ((float)letter_count / word_count) * 100;
    float average_sentences = ((float)sentence_count / word_count) * 100;
    
    float readability_index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    int grade_level = round(readability_index);
    
    if (grade_level < 1) {
        printf("Before Grade 1\n");
    } 
    else if (grade_level >= 16) {
        printf("Grade 16+\n");
    } 
    else {
        printf("Grade %d\n", grade_level);
    }
    
    return 0;
}