#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    char plaintext[1000];
    int key;
    printf("Key(number of shifts): ");
    scanf("%d", &key);
    getchar();
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    size_t len = strlen(plaintext);
    if(len>0 && plaintext[len - 1] == '\n')
    {
        plaintext[len - 1] = '\0';
    }
    printf("ciphertext: ");
    for(int i=0; plaintext[i]!='\0'; i++)
    {
        char c = plaintext[i];
        if(isupper(c))
        {
            printf("%c", ((c- 'A' +key)%26)+'A');
        }
        else if(islower(c))
        {
            printf("%c", ((c- 'a' +key)%26)+'a');
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
