#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int key;

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &key);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isupper(plaintext[i])) {
            putchar('A' + (plaintext[i] - 'A' + key) % 26);
        } else if (islower(plaintext[i])) {
            putchar('a' + (plaintext[i] - 'a' + key) % 26);
        } else {
            putchar(plaintext[i]);
        }
    }
    return 0;
}