#include <stdio.h>
#include <ctype.h>

int main() {
    int key;
    char text[1000];
    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); // clear newline
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

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
