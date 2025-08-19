#include <stdio.h>

int main() {
    char text[1000];
    int key, i;

    
    printf("Enter key (number of positions to shift): ");
    scanf("%d", &key);

    
    getchar();

    
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    
    for (i = 0; text[i] != '\0'; i++) {
        
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
        
    }

    
    printf("ciphertext: %s\n", text);

    return 0;
}