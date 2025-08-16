#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[1000];
    int key;

    printf("Enter the key: ");
    scanf("%d", &key);
    getchar();  // Consume newline after key input

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            printf("%c", ((ch - 'A' + key) % 26) + 'A');
        } else if (islower(ch)) {
            printf("%c", ((ch - 'a' + key) % 26) + 'a');
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}
