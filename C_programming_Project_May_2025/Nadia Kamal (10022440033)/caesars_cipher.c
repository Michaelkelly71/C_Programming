#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int key;

    // Ask for key
    printf("Key: ");
    scanf("%d", &key);

    // Clear newline left in buffer
    getchar();

    // Ask for plaintext
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isalpha(c)) {
            // Shift depending on case
            if (isupper(c)) {
                c = ((c - 'A' + key) % 26) + 'A';
            } else {
                c = ((c - 'a' + key) % 26) + 'a';
            }
        }
        putchar(c);
    }

    printf("\n");
    return 0;
}
