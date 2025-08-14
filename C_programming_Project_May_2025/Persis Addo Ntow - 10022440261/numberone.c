#include <stdio.h>

int getArraySum(int numbers[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += numbers[i];
    }
    return total;
}

int main() {
    int inputNumbers[5];

    printf("Please enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &inputNumbers[i]);
    }

    int totalSum = getArraySum(inputNumbers, 5);

    if (totalSum % 2 == 0) {
        printf("The sum is Even.\n");
    } else {
        printf("The sum is Odd.\n");
    }

    printf("Numbers in reverse order:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", inputNumbers[i]);
    }

    printf("\n");
    return 0;
}

