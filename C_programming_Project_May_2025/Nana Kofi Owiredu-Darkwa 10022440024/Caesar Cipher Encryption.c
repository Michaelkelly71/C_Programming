#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int key;
    char plaintext[1000], ciphertext[1000];

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); // clear newline from buffer

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext[i] = (c - base + key) % 26 + base;
        } else {
            ciphertext[i] = c;
        }
    }

    ciphertext[strlen(plaintext)] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
