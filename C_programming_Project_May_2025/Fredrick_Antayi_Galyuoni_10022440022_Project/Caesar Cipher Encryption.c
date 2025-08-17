//Caesar Cipher Encryption
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[500];
    int key;

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char encrypted = (text[i] - base + key) % 26 + base;
            printf("%c", encrypted);
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
