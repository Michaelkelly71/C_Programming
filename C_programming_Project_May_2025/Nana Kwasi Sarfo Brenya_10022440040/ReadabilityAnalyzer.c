#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
        if (isspace(text[i]) || text[i] == '\n') {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    if (text[0] != '\0' && text[strlen(text) - 1] != ' ' && text[strlen(text) - 1] != '\n') {
        words++;
    }


    double L = (letters / (double)words) * 100;
    double S = (sentences / (double)words) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;


    int grade_level = (int)(index + 0.5); 

    if (grade_level < 1) {
        printf("Before Grade 1\n");
    } else if (grade_level >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade_level);
    }

    return 0;
}
