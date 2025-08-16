#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int key;
    char text[1000];
    
    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); 
    
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        } else if (islower(c)) {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        } else {
            printf("%c", c);
        }
    }
    return 0;
}