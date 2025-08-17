#include <stdio.h>
#include <ctype.h>

int main(void) {
    long key;
    char plaintext[10000];

    printf("Key: ");
    if (scanf("%ld%*c", &key) != 1) return 1; 
    key = (key % 26 + 26) % 26;              

    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin)) return 1;

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        unsigned char c = (unsigned char) plaintext[i];
        if (isalpha(c)) {
            int base = isupper(c) ? 'A' : 'a';
            int rotated = ( (c - base) + (int)key ) % 26;
            putchar(base + rotated);
        } else {
            putchar(c);
        }
    }
    return 0;
}
