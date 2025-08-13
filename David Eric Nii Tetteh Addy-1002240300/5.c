#include <stdio.h>
#include <string.h>
#include <ctype.h>

int startsWithVowel(const char *str) {
    if (str[0] == '\0') return 0;
    char first = tolower(str[0]);
    return first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u';
}

void printNamesReverse(char names[][100], int size) {
    printf("Names in reverse order:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%s\n", names[i]);
    }
}

int countTotalChars(char names[][100], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += strlen(names[i]);
    }
    return total;
}

int main() {
    char names[5][100];
    
    printf("Enter 5 names:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%99s", names[i]);
    }
    
    if (startsWithVowel(names[1])) {
        printf("Second name starts with a vowel. Skipping last name.\n");
        printNamesReverse(names, 4); 
    } else {
        printNamesReverse(names, 5);
    }
    
    printf("Total characters in all names: %d\n", countTotalChars(names, 5));
    
    return 0;
}