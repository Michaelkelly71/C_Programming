#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plaintext[1000];
    int key;

    // Get input
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character if present
    size_t len = strlen(plaintext);
    if (plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Get the key
    printf("Enter key (0-25): ");
    scanf("%d", &key);

    // Ensure key is within range
    key = key % 26;

    // Encrypt
    char ciphertext[1000];
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isupper(c)) {
            ciphertext[i] = ((c - 'A' + key) % 26) + 'A';
        } else if (islower(c)) {
            ciphertext[i] = ((c - 'a' + key) % 26) + 'a';
        } else {
            ciphertext[i] = c; // leave non-alphabet unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    // Output result
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}