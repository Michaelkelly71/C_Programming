#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[1000];
    int key;
    
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    
    key = key % 26;
    if (key < 0) key += 26;
    
    int length = strlen(plaintext);
    
    for (int i = 0; i < length; i++) {
        char c = plaintext[i];
        if (isupper(c)) {
            plaintext[i] = ((c - 'A' + key) % 26) + 'A';
        } else if (islower(c)) {
            plaintext[i] = ((c - 'a' + key) % 26) + 'a';
        }
    }
    
    printf("ciphertext: %s", plaintext);
    return 0;
}