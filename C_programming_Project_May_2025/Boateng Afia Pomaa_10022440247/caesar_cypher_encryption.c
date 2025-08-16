#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    for (int i = 0; text[i]; i++) {
        if (isupper(text[i])) text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (islower(text[i])) text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
    printf("ciphertext: %s", text);
    return 0;
}