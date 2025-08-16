#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[1000];   // store input message
    char ciphertext[1000];  // store encrypted message
    int key;

    // Ask user for input
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin); // read whole line (including spaces)

    printf("Enter key (number of positions to shift): ");
    scanf("%d", &key);

    // Encrypt each character
    for (int i = 0; i < strlen(plaintext); i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            // A = 65 in ASCII → shift within 0–25 range, then add back 65
            ciphertext[i] = ( (ch - 'A' + key) % 26 ) + 'A';
        }
        else if (islower(ch)) {
            // a = 97 in ASCII → shift within 0–25 range, then add back 97
            ciphertext[i] = ( (ch - 'a' + key) % 26 ) + 'a';
        }
        else {
            // Non-alphabet characters remain unchanged
            ciphertext[i] = ch;
        }
    }

    ciphertext[strlen(plaintext)] = '\0'; // null terminate string

    // Print result
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}