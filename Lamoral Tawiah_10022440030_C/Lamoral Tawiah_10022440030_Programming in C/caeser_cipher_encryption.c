#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char plaintext[1000];
    int key;

    printf("Enter key: ");
    scanf("%d", &key);

    printf("plaintext: ");
    getchar();
    fgets(plaintext, sizeof(plaintext), stdin);

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            plaintext[i] = 'A' + (c - 'A' + key) % 26;
        }
        else if (islower(c))
        {
            plaintext[i] = 'a' + (c - 'a' + key) % 26;
        }
    }

    printf("ciphertext: %s", plaintext);

    return 0;
}
