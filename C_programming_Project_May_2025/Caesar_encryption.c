#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plaintext[1000];
    int key;
    
    printf("Enter the key (shift amount): ");
    scanf("%d", &key);
    getchar(); 

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    size_t len = strlen(plaintext);
    if (plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isupper(c)) {
            char encrypted = ((c - 'A' + key) % 26) + 'A';
            printf("%c", encrypted);
        } else if (islower(c)) {
            char encrypted = ((c - 'a' + key) % 26) + 'a';
            printf("%c", encrypted);
        } else {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
