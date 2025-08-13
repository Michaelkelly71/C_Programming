#include <stdio.h>

double findMax(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    double arr[5];
    
    printf("Enter 5 double values:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%lf", &arr[i]);
    }
    
    double max = findMax(arr, 5);
    if (max > 100.00) {
        printf("High Value Detected\n");
    } else {
        printf("All Values Normal\n");
    }
    
    printf("Values squared:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2lf ", arr[i] * arr[i]);
    }
    
    return 0;
}