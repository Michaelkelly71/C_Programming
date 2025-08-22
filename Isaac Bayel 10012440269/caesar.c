#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    // Get the key (shift amount)
    printf("Enter key (number of shifts): ");
    scanf("%d", &key);
    getchar(); // to clear newline left in input

    // Get the plaintext message
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        } else if (islower(c)) {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        } else {
            printf("%c", c); // leave non-letters unchanged
        }
    }
    printf("\n");
    return 0;
}
