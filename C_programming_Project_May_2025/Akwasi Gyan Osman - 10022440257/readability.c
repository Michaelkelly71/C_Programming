#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char text[2000];
    int letters = 0, words = 0, sentences = 0;

    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin)) return 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) letters++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') sentences++;
        if (isspace((unsigned char)text[i])) words++;
    }
    words++; 

    float L = (letters / (float)words) * 100.0f;
    float S = (sentences / (float)words) * 100.0f;
    int grade = (int)lroundf(0.0588f * L - 0.296f * S - 15.8f);

    if (grade < 1)       printf("Before Grade 1\n");
    else if (grade >=16) printf("Grade 16+\n");
    else                 printf("Grade %d\n", grade);
    return 0;
}
