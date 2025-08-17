#include <stdio.h>

int main() {
    char text[1000];
    int key = 3;
    
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    
    printf("ciphertext: ");
    
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        
        if (c >= 'A' && c <= 'Z') {
            // Uppercase letters: shift within A-Z range
            putchar('A' + (c - 'A' + key) % 26);
        } 
        else if (c >= 'a' && c <= 'z') {
            // Lowercase letters: shift within a-z range
            putchar('a' + (c - 'a' + key) % 26);
        } 
        else {
            // Non-alphabetic characters stay unchanged
            putchar(c);
        }
    }
    
    return 0;
}