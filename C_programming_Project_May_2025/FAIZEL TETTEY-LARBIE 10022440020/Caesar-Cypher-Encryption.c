#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[1000];
    int key;

    // Ask for key
    printf("Enter key (shift amount): ");
    scanf("%d", &key);
    getchar(); // Remove leftover newline from buffer

    // Ask for plaintext
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encrypted = (ch - base + key) % 26 + base;
            printf("%c", encrypted);
        } else {
            printf("%c", ch); // Leave non-letters unchanged
        }
    }
    printf("\n");

    return 0;
}
