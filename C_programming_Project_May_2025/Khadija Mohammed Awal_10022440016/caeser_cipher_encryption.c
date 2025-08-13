#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[500];
    int key;

    printf("Key: ");
    scanf("%d", &key);
    getchar(); 

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
