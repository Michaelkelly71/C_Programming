#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int encryption_key;

    printf("Key: ");
    scanf("%d", &encryption_key);
    getchar(); 

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char current_char = plaintext[i];

        if (isalpha(current_char)) {
        
            char base = isupper(current_char) ? 'A' : 'a';
            current_char = (current_char - base + encryption_key) % 26 + base;
        }
        
        printf("%c", current_char);
    }
    printf("\n");

    return 0;
}