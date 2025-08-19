#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char plaintext[1000];
    int key;

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("key: ");
    scanf("%i", &key);

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char current_char = plaintext[i];
        if (isalpha(current_char))
        {
            char base;
            if (isupper(current_char))
            {
                base = 'A';
            }
            else
            {
                base = 'a';
            }
            char encrypted_char = (current_char - base + key) % 26 + base;
            printf("%c", encrypted_char);
        }
        else
        {
            printf("%c", current_char);
        }
    }
    printf("\n");

    return 0;
}
