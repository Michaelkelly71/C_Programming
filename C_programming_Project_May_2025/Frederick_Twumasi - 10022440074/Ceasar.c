#include <stdio.h>

int main() {
    char text[1000];
    int key;
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Key: ");
    scanf("%d", &key);
    key %= 26;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }

    printf("ciphertext: %s", text);
    return 0;
}
