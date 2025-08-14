#include <stdio.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void printReversed(char characters[], int length) {
    printf("Characters in reverse order: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c ", characters[i]);
    }
    printf("\n");
}

int countConsonants(char characters[], int length) {
    int consonantCount = 0;
    for (int i = 0; i < length; i++) {
        char ch = tolower(characters[i]);
        if (isalpha(ch) && !isVowel(ch)) {
            consonantCount++;
        }
    }
    return consonantCount;
}

int main() {
    char input[5];

    printf("Enter 5 characters:\n");
    for (int i = 0; i < 5; i++) {
        scanf(" %c", &input[i]); 
    }

    if (isVowel(input[0])) {
        printf("The first character is a vowel.\n");
    } else {
        printf("The first character is not a vowel.\n");
    }

    printReversed(input, 5);

    int consonants = countConsonants(input, 5);
    printf("Total number of consonants: %d\n", consonants);

    return 0;
}
