#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char plaintext[1000];
    int key;
    
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    printf("Enter key (shift amount): ");
    scanf("%d", &key);
    
    // Ensure key is within 0-25
    key = key % 26;
    
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char encrypted = (plaintext[i] - base + key) % 26 + base;
            printf("%c", encrypted);
        } else {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    return 0;
}