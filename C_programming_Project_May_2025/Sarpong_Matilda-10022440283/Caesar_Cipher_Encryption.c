#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int key;
    char plaintext[1000];

    printf("Key (number of positions to shift): ");
    scanf("%d", &key);
    getchar(); 
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isupper(ch)) {
            printf("%c", (ch - 'A' + key) % 26 + 'A');
        } else if (islower(ch)) {
            printf("%c", (ch - 'a' + key) % 26 + 'a');
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}