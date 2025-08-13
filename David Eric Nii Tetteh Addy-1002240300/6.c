#include <stdio.h>
#include <string.h>
#include <ctype.h>

int sumIntegers(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

float sumFloats(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

double sumDoubles(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

void printChars(char arr[], int size) {
    for (int i = 0; i < size; i++) printf("%c ", arr[i]);
    printf("\n");
}

void printStrings(char arr[][20], int size) {
    for (int i = 0; i < size; i++) printf("%s\n", arr[i]);
}

int main() {
    int ints[2];
    float floats[2];
    double doubles[2];
    char chars[2];
    char strings[2][20];

    printf("Enter 2 integers: ");
    for (int i = 0; i < 2; i++) scanf("%d", &ints[i]);

    printf("Enter 2 floats: ");
    for (int i = 0; i < 2; i++) scanf("%f", &floats[i]);

    printf("Enter 2 doubles: ");
    for (int i = 0; i < 2; i++) scanf("%lf", &doubles[i]);

    printf("Enter 2 characters: ");
    for (int i = 0; i < 2; i++) scanf(" %c", &chars[i]);

    printf("Enter 2 strings: ");
    for (int i = 0; i < 2; i++) scanf("%s", strings[i]);

    for (int i = 0; i < 2; i++) {
        if ((ints[i] + floats[i]) > 100) {
            printf("Big Sum!\n");
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        char first = tolower(strings[i][0]);
        if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
            printf("Special Name Detected\n");
            break;
        }
    }

    printf("\nIntegers in reverse: %d %d\n", ints[1], ints[0]);
    printf("Floats in reverse: %.2f %.2f\n", floats[1], floats[0]);
    printf("Doubles in reverse: %.2lf %.2lf\n", doubles[1], doubles[0]);
    printf("Chars in reverse: %c %c\n", chars[1], chars[0]);
    printf("Strings in reverse: %s %s\n", strings[1], strings[0]);

    return 0;
}
