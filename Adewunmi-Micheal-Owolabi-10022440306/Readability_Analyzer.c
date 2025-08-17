#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int letters = 0, words = 1, sentences = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++;
        } else if (text[i] == ' ') {
            words++;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);

    return 0;
}
