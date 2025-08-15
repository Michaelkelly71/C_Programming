#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plaintext[1000];
    int key;

    printf("Key: ");
    scanf("%d", &key);
    getchar(); // clear newline from buffer

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}
