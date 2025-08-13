#include <stdio.h>

int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    char plaintext[1000];
    int key;
    
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (is_upper(plaintext[i])) {
            printf("%c", 'A' + (plaintext[i] - 'A' + key) % 26);
        } else if (is_lower(plaintext[i])) {
            printf("%c", 'a' + (plaintext[i] - 'a' + key) % 26);
        } else {
            printf("%c", plaintext[i]);
        }
    }
    
    return 0;
}