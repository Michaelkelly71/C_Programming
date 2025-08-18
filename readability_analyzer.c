#include <stdio.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0;
    float L, S, index;
    int i = 0;

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    while (text[i] != '\0') {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        } else if (text[i] == ' ') {
            words++;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
        i++;
    }

    L = (letters / (float)words) * 100;
    S = (sentences / (float)words) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)(index + 0.5); 

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else{
        printf("Grade %d\n", grade);
    }

    return 0;

}