#include <stdio.h>

int main() {
    char plaintext[1000];
    int key, i = 0;
    
    printf("plaintext: ");
    gets(plaintext);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    printf("ciphertext: ");
    
    while(plaintext[i] != '\0') {
        // For uppercase letters
        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            char encrypted = plaintext[i] - 'A';
            encrypted = (encrypted + key) % 26;
            printf("%c", encrypted + 'A');
        }
        // For lowercase letters
        else if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            char encrypted = plaintext[i] - 'a';
            encrypted = (encrypted + key) % 26;
            printf("%c", encrypted + 'a');
        }
        // For other characters
        else {
            printf("%c", plaintext[i]);
        }
        i++;
    }
    
    return 0;
}