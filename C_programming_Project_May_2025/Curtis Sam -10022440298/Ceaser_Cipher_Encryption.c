#include <stdio.h>

int main() {
    char text[200];
    int key, i = 0;

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); 

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    while (text[i] != '\0') {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + key) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + key) % 26) + 'a';
        }
        printf("%c", c);
        i++;
    }

    return 0;
}