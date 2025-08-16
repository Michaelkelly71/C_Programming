#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char plaintext[1000], ciphertext[1000];
    int key = 3; 
    
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    plaintext[strcspn(plaintext, "\n")] = '\0';
    
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isupper(plaintext[i])) {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else if (islower(plaintext[i])) {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    
    ciphertext[strlen(plaintext)] = '\0';
    
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}


