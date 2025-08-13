#include <stdio.h>

float calculateAverage(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    float arr[5];
    
    printf("Enter 5 floating-point numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &arr[i]);
    }
    
    float avg = calculateAverage(arr, 5);
    if (avg > 50) {
        printf("Above Average\n");
    } else {
        printf("Below Average\n");
    }
    
    printf("Numbers doubled:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", arr[i] * 2);
    }
    
    return 0;
}