#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[500];
    int key;
    
    printf("Enter plaintext: ");
    fgets(plaintext, 500, stdin);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    
    key = key % 26;
    
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isupper(plaintext[i])) {
            char koko = ((plaintext[i] - 'A' + key) % 26) + 'A';
            putchar(koko);
        } else if (islower(plaintext[i])) {
            char koose = ((plaintext[i] - 'a' + key) % 26) + 'a';
            putchar(koose);
        } else {
            putchar(plaintext[i]);
        }
    }
    
    return 0;
}