#include <stdio.h>
#include <ctype.h>

int main(void) {
    char message[500];
    int shift;
    
    printf("plaintext: ");
    fgets(message, 500, stdin);
    
    printf("Enter key: ");
    scanf("%d", &shift);
    
    
    shift = shift % 26;
    if (shift < 0) shift += 26;
    
    printf("ciphertext: ");
    for (int i = 0; message[i] != '\0'; i++) {
        if (isupper(message[i])) {
            char coded = ((message[i] - 'A' + shift) % 26) + 'A';
            putchar(coded);
        } else if (islower(message[i])) {
            char coded = ((message[i] - 'a' + shift) % 26) + 'a';
            putchar(coded);
        } else {
            putchar(message[i]);
        }
    }
    
    return 0;
}