#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline

    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isupper(plaintext[i])) {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        } else if (islower(plaintext[i])) {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}