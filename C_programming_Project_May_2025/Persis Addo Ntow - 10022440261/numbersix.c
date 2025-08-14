#include <stdio.h>
#include <string.h>
#include <ctype.h>

int startsWithVowel(const char *word) {
    if (word[0] == '\0') return 0; 
    char first = tolower(word[0]);
    return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u');
}

void reverseAndPrintInts(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseAndPrintFloats(float arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void reverseAndPrintDoubles(double arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
}

void reverseAndPrintChars(char arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void reverseAndPrintStrings(char arr[][100], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {

    int nums[2];
    float decimals[2];
    double bigDecimals[2];
    char letters[2];
    char words[2][100];

    printf("Enter 2 integers:\n");
    for (int i = 0; i < 2; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter 2 float numbers:\n");
    for (int i = 0; i < 2; i++) {
        scanf("%f", &decimals[i]);
    }

    printf("Enter 2 double numbers:\n");
    for (int i = 0; i < 2; i++) {
        scanf("%lf", &bigDecimals[i]);
    }

    printf("Enter 2 characters:\n");
    for (int i = 0; i < 2; i++) {
        scanf(" %c", &letters[i]); 
    }

    printf("Enter 2 strings:\n");
    for (int i = 0; i < 2; i++) {
        scanf("%99s", words[i]);
    }

    for (int i = 0; i < 2; i++) {
        if (nums[i] + decimals[i] > 100.0) {
            printf("Big Sum Detected!\n");
            break;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (startsWithVowel(words[i])) {
            printf("Special Name Found\n");
            break;
        }
    }

    printf("\nReversed Input Data:\n");

    printf("Integers: ");
    reverseAndPrintInts(nums, 2);

    printf("Floats: ");
    reverseAndPrintFloats(decimals, 2);

    printf("Doubles: ");
    reverseAndPrintDoubles(bigDecimals, 2);

    printf("Characters: ");
    reverseAndPrintChars(letters, 2);

    printf("Strings: ");
    reverseAndPrintStrings(words, 2);

    return 0;
}