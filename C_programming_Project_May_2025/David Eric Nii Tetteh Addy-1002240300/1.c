#include <stdio.h>

int computeTotal(int numbers[], int count) {
    int total = 0;
    for (int j = 0; j < count; j++) {
        total += numbers[j];
    }
    return total;
}

int main() {
    int values[5];
    printf("Please enter 5 numbers: ");
    for (int k = 0; k < 5; k++) {
        scanf("%d", &values[k]);
    }

    int result = computeTotal(values, 5);

    if (result % 2 == 0)
        printf("Even Total\n");
    else
        printf("Odd Total\n");

    printf("Reversed numbers: ");
    for (int m = 4; m >= 0; m--) {
        printf("%d ", values[m]);
    }
    printf("\n");

    return 0;
}