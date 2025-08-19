#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char passage[1000];
    int letterCount = 0, wordCount = 1, sentenceCount = 0;
    float avgLetters, avgSentences, score;

    printf("Input text: ");
    fgets(passage, sizeof(passage), stdin);

    for (int k = 0; passage[k] != '\0'; k++) {
        char current = passage[k];
        if (isalpha(current)) {
            letterCount++;
        } else if (current == ' ') {
            wordCount++;
        } else if (current == '.' || current == '!' || current == '?') {
            sentenceCount++;
        }
    }

    avgLetters = ((float)letterCount / wordCount) * 100;
    avgSentences = ((float)sentenceCount / wordCount) * 100;
    score = 0.0588 * avgLetters - 0.296 * avgSentences - 15.8;

    int readability = round(score);

    if (readability < 1) {
        printf("Before Grade 1\n");
    } else if (readability >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", readability);
    }

    return 0;
}