#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 5
#define NAME_LENGTH 100

int beginsWithVowel(const char *name) {
    if (name[0] == '\0') return 0;
    char firstChar = tolower(name[0]);
    return (firstChar == 'a' || firstChar == 'e' || 
            firstChar == 'i' || firstChar == 'o' || 
            firstChar == 'u');
}

void displayReversedNames(char names[][NAME_LENGTH], int count) {
    printf("Names in reverse order:\n");
    for (int idx = count - 1; idx >= 0; idx--) {
        printf("%s\n", names[idx]);
    }
}

int calculateTotalCharacters(char names[][NAME_LENGTH], int count) {
    int charCount = 0;
    for (int idx = 0; idx < count; idx++) {
        charCount += strlen(names[idx]);
    }
    return charCount;
}

int main() {
    char nameList[MAX_NAMES][NAME_LENGTH];
    
    printf("Enter %d names:\n", MAX_NAMES);
    for (int i = 0; i < MAX_NAMES; i++) {
        scanf("%99s", nameList[i]);
    }
    
    if (beginsWithVowel(nameList[1])) {
        printf("Second name begins with a vowel. Omitting last name.\n");
        displayReversedNames(nameList, MAX_NAMES - 1);
    } else {
        displayReversedNames(nameList, MAX_NAMES);
    }
    
    printf("Total characters in all names: %d\n", 
           calculateTotalCharacters(nameList, MAX_NAMES));
    
    return 0;
}
