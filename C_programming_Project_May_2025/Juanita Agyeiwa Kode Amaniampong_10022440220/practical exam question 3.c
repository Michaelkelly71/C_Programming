#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key) % 26 + base;
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
