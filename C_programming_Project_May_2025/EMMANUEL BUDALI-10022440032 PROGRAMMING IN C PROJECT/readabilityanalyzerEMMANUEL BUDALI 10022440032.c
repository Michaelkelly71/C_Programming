#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(const char *text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) count++;
    }
    return count;
}

int count_words(const char *text) {
    int count = 0, in_word = 0;
    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
    }
    return count;
}

int count_sentences(const char *text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') count++;
    }
    return count;
}

int main(void) {
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = words > 0 ? (float)letters / words * 100 : 0;
    float S = words > 0 ? (float)sentences / words * 100 : 0;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)round(index);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
