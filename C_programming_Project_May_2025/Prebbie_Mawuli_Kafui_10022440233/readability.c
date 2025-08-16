#include <stdio.h>
#include <ctype.h>

#define MAX_TEXT 1000

int main() {
    char text[MAX_TEXT];
    int letters = 0, words = 0, sentences = 0;
    bool in_word = false;

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            letters++;
            in_word = true;
        }
        else if (isspace(text[i])) {
            words += in_word;
            in_word = false;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
            words += in_word;
            in_word = false;
        }
    }
    words += in_word; 

    float L = words ? (letters * 100.0f) / words : 0;
    float S = words ? (sentences * 100.0f) / words : 0;
    int grade = 0.0588 * L - 0.296 * S - 15.8 + 0.5;

    printf(grade < 1 ? "Before Grade 1\n" :
           grade >= 16 ? "Grade 16+\n" : "Grade %d\n", grade);

    return 0;
}