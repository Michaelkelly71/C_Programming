#include <stdio.h>

int main() {
    int key;
    char text[1000];

    printf("Key: ");
    scanf("%d", &key);
    getchar();  

    printf("plaintext: ");
    fgets(text, 1000, stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        else if (c >= 'a' && c <= 'z')
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        else
            printf("%c", c);
    }
    return 0;
}