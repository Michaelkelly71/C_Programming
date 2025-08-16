#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[1000];
    int key;

    printf("Key: ");
    scanf("%d", &key);
    getchar(); // remove newline from input buffer

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}