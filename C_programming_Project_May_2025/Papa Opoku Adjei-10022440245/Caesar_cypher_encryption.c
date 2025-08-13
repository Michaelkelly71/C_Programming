#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    
    printf("Plaintext: ");
    fgets(text, sizeof(text), stdin);

    
    printf("Enter key (integer): ");
    scanf("%d", &key);

    
    key = key % 26;

    
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + key) % 26) + base;
        }

        text[i] = c; 
    }

    printf("Ciphertext: %s\n", text);

    return 0;
}