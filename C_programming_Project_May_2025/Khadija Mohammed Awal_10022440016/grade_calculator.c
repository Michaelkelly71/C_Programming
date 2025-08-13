#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function to count letters (A-Z, a-z)
int count_letters(const char *text) {
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }
    return letters;
}

// Function to count words (sequences separated by spaces)
int count_words(const char *text) {
    int words = 0, in_word = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        words++;
    }
    return words;
}

// Function to count sentences (ending with '.', '!', '?')
int count_sentences(const char *text) {
    int sentences = 0 , words;
    for (int i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case '.':
            case '!':
            case '?':
                sentences++;
                break;
            default:
                break;
        }
    }
    return (words > 0 && sentences == 0) ? 1 : sentences;
}

// Function to calculate Coleman-Liau Index
int calculate_grade(int letters, int words, int sentences) {
    if (words == 0) return 0; // Avoid division by zero
    double L = (100.0 * letters) / words;
    double S = (100.0 * sentences) / words;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    return (int) round(index);
}

// Function to write result to file
void write_result_to_file(int grade) {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        return;
    }
    if (grade < 1) {
        fprintf(fp, "Before Grade 1\n");
    } else if (grade >= 16) {
        fprintf(fp, "Grade 16+\n");
    } else {
        fprintf(fp, "Grade %d\n", grade);
    }
    fclose(fp);
}

int main() {
    char text[1024];
    char source[20];
    printf("Enter 'console' to input text or 'file' to read from input.txt: ");
    scanf("%s", source);
    getchar(); // Clear newline from scanf

    // Read input
    if (strcmp(source, "file") == 0) {
        FILE *fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("Error: Cannot open input.txt\n");
            return 1;
        }
        if (!fgets(text, sizeof(text), fp)) {
            printf("Error: Empty or invalid file\n");
            fclose(fp);
            return 1;
        }
        fclose(fp);
    } else {
        printf("Text: ");
        fgets(text, sizeof(text), stdin);
    }

    // Remove trailing newline
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    // Validate input
    if (len == 0) {
        printf("Error: Empty input\n");
        return 1;
    }

    // Process text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = calculate_grade(letters, words, sentences);

    // Output to console
    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }

    // Write to file
    write_result_to_file(grade);

    return 0;
}