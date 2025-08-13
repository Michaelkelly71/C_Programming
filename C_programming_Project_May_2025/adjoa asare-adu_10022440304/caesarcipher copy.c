#include <stdio.h>
#include <ctype.h>  // For isalpha, isupper, islower
#include <string.h> // For strlen

int main() {
    char plaintext[1000];
    int key;

    // Input: plaintext
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input: key
    printf("Enter key: ");
    scanf("%d", &key);

    // Ensure key stays within range 0-25
    key = key % 26;

    char ciphertext[1000];
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];

        if (isalpha(c)) {  
            if (isupper(c)) {
                c = ((c - 'A' + key) % 26) + 'A';
            } else if (islower(c)) {
                c = ((c - 'a' + key) % 26) + 'a';
            }
        }
        ciphertext[i] = c;  
    }
    ciphertext[i] = '\0'; // Null terminate the string

    // Output
    printf("ciphertext: %s\n", ciphertext);

    return 0; // Program completed successfully
}
