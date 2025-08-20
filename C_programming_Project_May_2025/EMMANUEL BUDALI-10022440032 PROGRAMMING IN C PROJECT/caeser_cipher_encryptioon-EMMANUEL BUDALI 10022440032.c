#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char caesar_shift(char ch, int key) {
    if (isupper(ch)) {
        return (ch - 'A' + key) % 26 + 'A';
    } else if (islower(ch)) {
        return (ch - 'a' + key) % 26 + 'a';
    }
    return ch;
}

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
    plaintext[strcspn(plaintext, "\n")] = '\0';

    char ciphertext[1000];
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = caesar_shift(plaintext[i], key);
    }
    ciphertext[len] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
