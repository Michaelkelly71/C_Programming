#include <stdio.h>

#define ARRAY_SIZE 5
#define AVERAGE_THRESHOLD 50.0f

float enterMean(float numbers[], int count) {
    float total = 0.0f;
    
    for (int index = 0; index < count; index++) {
        total += numbers[index];
    }
    
    return total / (float)count;
}

void displayDoubledValues(float values[], int length) {
    printf("Numbers doubled:\n");
    for (int i = 0; i < length; i++) {
        printf("%.2f ", values[i] * 2);
    }
}

int main() {
    float userInput[ARRAY_SIZE];
    
    printf("Enter %d floating-point numbers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%f", &userInput[i]);
    }
    
    float meanValue = enterMean(userInput, ARRAY_SIZE);
    
    printf(meanValue > AVERAGE_THRESHOLD ? "Above Average\n" : "Below Average\n");
    
    displayDoubledValues(userInput, ARRAY_SIZE);
    
    return 0;
}