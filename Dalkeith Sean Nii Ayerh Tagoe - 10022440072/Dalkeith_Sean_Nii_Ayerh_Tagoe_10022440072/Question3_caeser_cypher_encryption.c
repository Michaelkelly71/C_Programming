// Question 3 caeser cypher encryption

#include <stdio.h>
#include <ctype.h>

int main(void) {
    long key;
    char text[10000];

    printf("Key: ");
    if (scanf("%ld", &key) != 1) return 1;
    // consume leftover newline
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    key = (key % 26 + 26) % 26; // normalize to [0,25]

    printf("plaintext: ");
    if (!fgets(text, sizeof(text), stdin)) return 1;

    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char c = (unsigned char)text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int pi = c - base;
            int ci = (pi + (int)key) % 26;
            text[i] = (char)(base + ci);
        }
    }

    printf("ciphertext: %s", text);
    return 0;
}