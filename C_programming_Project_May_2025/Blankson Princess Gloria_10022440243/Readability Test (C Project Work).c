#include  <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL_CAPACITY 10
#define FORMULA_A 0.0588
#define FORMULA_B 0.296
#define FORMULA_C 15.8

int main() {
    char * text = NULL;
    int size = 0;
    int capacity = INITIAL_CAPACITY;
    char ch;

    text = (char *)malloc(capacity * sizeof(char));
    if (text == NULL) {
        printf("Memory allocation failed. \n");
        return 1;
    }

    printf("Text: ");
    
    while ((ch = getchar () ) != '\n') {
        if (size >= capacity) {
            capacity *= 2;
            char *temp = realloc(text,capacity * sizeof(char));
            if (temp == NULL) {
                printf("Memory allocation failed. \n");
                free(text);
                return 1;
            }
            text = temp;

        }
        text[size ++] = ch ;
    }
    text[size] = '\0';

    int letters = 0, words = 0, sentences = 0;

    for (int i = 0; i <size; i ++) {
        char c = text [i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
           letters ++; 
        } else if (c == ' '){
            words++;
        } else if (c == '.' || c == '!' || c == "?") {
            sentences++;
        }
    }

    words++;

    float L = (float)letters/words * 100;
    float S = (float)sentences/words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1) {
        printf("Before grade 1");
    } else if (grade >= 16) {
        printf("Grade 16+ \n ");
    } else{
        printf("Grade %d\n", grade);
    }

    free(text);
    return 0;
}



    


