#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0, words = 1, sentences = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]))
            letters++;
        else if (text[i] == ' ')
            words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", index);

    return 0;
}
