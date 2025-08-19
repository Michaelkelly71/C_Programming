#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[2000];
    int key;

    printf("Enter key (number of shifts): ");
    if (scanf("%d", &key) != 1) return 0;
    key %= 26; // normalize
    getchar(); // consume newline

    printf("plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 0;

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char c = (unsigned char)text[i];
        if (isalpha(c)) {
            unsigned char base = isupper(c) ? 'A' : 'a';
            putchar((int)((c - base + key) % 26 + base));
        } else {
            putchar(c);
        }
    }
    return 0;
}
