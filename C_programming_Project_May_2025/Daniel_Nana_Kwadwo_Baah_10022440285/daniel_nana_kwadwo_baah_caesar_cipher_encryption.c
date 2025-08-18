#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%d", &key);
    key = key % 26;  // keep key within alphabet

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            putchar(((c - 'A' + key) % 26) + 'A');
        } else if (islower(c)) {
            putchar(((c - 'a' + key) % 26) + 'a');
        } else {
            putchar(c); // leave punctuation, spaces
        }
    }
    printf("\n");

    return 0;
}
