#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0, words = 1, sentences = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            letters++;
        }
        if (text[i] == ' ') {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    float raw_index = 0.0588 * L - 0.296 * S - 15.8;

    int index = (raw_index >= 0) ? (int)(raw_index + 0.5) : (int)(raw_index - 0.5);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}
