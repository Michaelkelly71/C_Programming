#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int key;

    printf("Enter key (number of positions to shift): ");
    if (scanf("%d", &key) != 1) {
        return 0;
    }
    getchar(); 

 
    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin)) {
        return 0;
    }

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isalpha((unsigned char)c)) {
            char base = isupper((unsigned char)c) ? 'A' : 'a';
            c = (c - base + key) % 26 + base; 
        }

        putchar(c);
    }
    printf("\n");

    return 0;
}
