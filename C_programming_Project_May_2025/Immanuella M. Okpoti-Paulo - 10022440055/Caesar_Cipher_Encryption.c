#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else
    {
        return c; 
    }
}

int main(void)
{
  
    int key = get_int("Key: ");

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}
