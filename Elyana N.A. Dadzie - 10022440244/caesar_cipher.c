#include <stdio.h>

int main() {
    char plaintext[1000], ciphertext[1000];
    int key, i;

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); // Clear newline

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = ((ch - 'A' + key) % 26) + 'A';
        }
        // Lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = ((ch - 'a' + key) % 26) + 'a';
        }
        // Leave unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}