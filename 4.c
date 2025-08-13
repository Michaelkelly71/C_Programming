#include <stdio.h>
#include <ctype.h>

void displayReverse(char arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main() {
    char arr[5];
    printf("Enter 5 characters: ");
    for (int i = 0; i < 5; i++) {
        scanf(" %c", &arr[i]);
    }

    char first = tolower(arr[0]);
    if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u')
        printf("Starts with a vowel\n");
    else
        printf("Does not start with a vowel\n");

    printf("Characters in reverse: ");
    displayReverse(arr, 5);

    int consonantCount = 0;
    for (int i = 0; i < 5; i++) {
        char ch = tolower(arr[i]);
        if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
            consonantCount++;
    }
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
