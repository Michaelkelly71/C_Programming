#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int key;
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
    }

    printf("ciphertext: %s", text);
    return 0;
}
