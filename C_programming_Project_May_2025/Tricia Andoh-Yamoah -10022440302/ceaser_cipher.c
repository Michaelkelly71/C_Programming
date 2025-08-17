#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Validate command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Validate key is a positive integer
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a positive integer\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;

    char plaintext[1000];
    // Prompt and read input
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline

    // Encrypt text
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
    }

    // Output ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}