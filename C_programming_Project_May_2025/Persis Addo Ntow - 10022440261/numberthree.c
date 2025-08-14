#include <stdio.h>

#define ARRAY_SIZE 5
#define HIGH_VALUE_THRESHOLD 100.0

double findLargestValue(double array[], int size) {
    double max = array[0]; 
    
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i]; 
        }
    }
    return max;
}

void printSquaredValues(double array[], int size) {
    printf("Squared values:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", array[i] * array[i]);
    }
    printf("\n");
}

int main() {
    double userNumbers[ARRAY_SIZE];

    printf("Please enter %d decimal numbers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%lf", &userNumbers[i]);
    }

    double largest = findLargestValue(userNumbers, ARRAY_SIZE);
    
    if (largest > HIGH_VALUE_THRESHOLD) {
        printf("High Value Detected\n");
    } else {
        printf("All Values Normal\n");
    }

    printSquaredValues(userNumbers, ARRAY_SIZE);

    return 0;
}