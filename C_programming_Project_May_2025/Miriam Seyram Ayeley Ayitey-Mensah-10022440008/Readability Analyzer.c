#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;

    printf("Enter key (number): ");
    scanf("%d", &key);
    getchar();

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = ((ch - offset + key) % 26) + offset;
        }

        printf("%c", ch);
    }
    printf("\n");

    return 0;
}


