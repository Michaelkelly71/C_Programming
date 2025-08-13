#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char plaintext[1000];
    int key;

    // Prompt user for key
    printf("Enter key (0-25): ");
    scanf("%d", &key);
    getchar(); // clear newline from buffer

    // Prompt for plaintext
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];
        if (isupper(ch))
            printf("%c", ((ch - 'A' + key) % 26) + 'A');
        else if (islower(ch))
            printf("%c", ((ch - 'a' + key) % 26) + 'a');
        else
            printf("%c", ch);
    }
    printf("\n");

    return 0;
}
