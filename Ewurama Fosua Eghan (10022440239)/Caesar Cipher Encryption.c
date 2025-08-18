#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    char line[5000];
    long key_input = 0;

    printf("Enter key (integer): ");
    if (!fgets(line, sizeof(line), stdin)) return 1;
    char *endptr = NULL;
    key_input = strtol(line, &endptr, 10);
    int key = (int)((key_input % 26 + 26) % 26); 

    
    char plaintext[5000];
    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin)) return 1;

    
    for (int i = 0; plaintext[i] != '\0'; i++) {
        unsigned char c = (unsigned char)plaintext[i];
        if (isalpha(c)) {
            int base = isupper(c) ? 'A' : 'a';
            int pi = c - base;
            int ci = (pi + key) % 26;
            plaintext[i] = (char)(base + ci);
        }
    }

    printf("ciphertext: %s", plaintext);
    return 0;
}
