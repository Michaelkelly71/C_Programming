#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]) % 26;
    char plaintext[1000];
    
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isupper(plaintext[i])) {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
        } else if (islower(plaintext[i])) {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
