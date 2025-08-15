#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[1000];
    int char_count = 0, word_count = 0, sentence_count = 0;
    int inside_word = 0;
    int i = 0;

    printf("Type your text: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            char_count++;
        }
        if (input[i] == '.' || input[i] == '!' || input[i] == '?') {
            sentence_count++;
        }
        if (isspace(input[i])) {
            if (inside_word) {
                word_count++;
                inside_word = 0;
            }
        } else {
            inside_word = 1;
        }
        i++;
    }
    if (inside_word) {
        word_count++;
    }

    double avg_letters = (char_count * 100.0) / word_count;
    double avg_sentences = (sentence_count * 100.0) / word_count;
    int level = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    if (level < 1) {
        printf("Before Grade 1\n");
    } else if (level >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", level);
    }

    return 0;
}