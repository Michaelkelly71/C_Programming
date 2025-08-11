#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0; 
    float L, S, index;

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        }
        if (text[i] == ' ') {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = (int)(index + 0.5);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
