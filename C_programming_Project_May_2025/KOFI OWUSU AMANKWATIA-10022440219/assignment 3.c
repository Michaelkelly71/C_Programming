#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    printf("Enter key (number of positions to shift): ");
    scanf("%d", &key);
    getchar(); // consume newline after key

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
    return 0;
}
