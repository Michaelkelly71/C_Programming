#include <stdio.h>
#include <math.h>   

int main() {
    char text[1000];
    int letters = 0, words = 0, sentences = 0, in_word = 0;

    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            letters++;

        if (c != ' ' && c != '\t' && c != '\n') {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }

        if (c == '.' || c == '!' || c == '?')
            sentences++;
    }

    double L = (double)letters * 100.0 / words;
    double S = (double)sentences * 100.0 / words;
    double idx = 0.0588 * L - 0.296 * S - 15.8;

    int grade = (int)round(idx);   
    
    printf("\n Your number of words are %d, your number of letters are %d and your number of sentences are %d.\n", words, letters, sentences);
    
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);

    return 0;
}
