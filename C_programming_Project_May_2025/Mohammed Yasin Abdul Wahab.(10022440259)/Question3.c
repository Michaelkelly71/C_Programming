#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt a character with Caesar's Cipher
char encrypt_char(char c, int key)
{
    if (isupper(c)) // Uppercase letters
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c)) // Lowercase letters
    {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else // Non-alphabetic characters remain unchanged
    {
        return c;
    }
}

int main(void)
{
    char plaintext[1000];
    int key;

    // Get the plaintext and key
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // Normalize key in case it’s larger than 26
    key = key % 26;

    // Encrypt text
    char ciphertext[1000];
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = encrypt_char(plaintext[i], key);
    }
    ciphertext[length] = '\0'; // null terminate

    // Output
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
