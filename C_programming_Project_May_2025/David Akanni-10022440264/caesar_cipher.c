//David Akanni
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            char encrypted = (c - offset + key) % 26 + offset;
            printf("%c", encrypted);
        } else {
            printf("%c", c); // Keep spaces/punctuation
        }
    }
    printf("\n");

    return 0;
}