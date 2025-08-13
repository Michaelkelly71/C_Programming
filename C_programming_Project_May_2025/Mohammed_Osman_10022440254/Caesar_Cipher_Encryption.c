

#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); // clear newline

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isupper(c))
            c = 'A' + (c - 'A' + key) % 26;
        else if (islower(c))
            c = 'a' + (c - 'a' + key) % 26;

        printf("%c", c);
    }
    return 0;
}

