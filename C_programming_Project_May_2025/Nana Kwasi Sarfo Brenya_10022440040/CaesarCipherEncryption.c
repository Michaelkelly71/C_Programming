#include <stdio.h>

int main() {
    char plaintext[100]; 
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin); 

    
    int key = 3; 
    char ciphertext[100]; 
    int i = 0;

    while (plaintext[i] != '\0') {
        char current_char = plaintext[i];

        if (current_char >= 'A' && current_char <= 'Z') {
            ciphertext[i] = (current_char - 'A' + key) % 26 + 'A';
        }
        else if (current_char >= 'a' && current_char <= 'z') {
            ciphertext[i] = (current_char - 'a' + key) % 26 + 'a';
        }
        else {
            ciphertext[i] = current_char;
        }

        i++;
    }

    ciphertext[i] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0; 
}
