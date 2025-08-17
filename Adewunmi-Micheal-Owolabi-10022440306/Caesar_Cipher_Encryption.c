#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }

    printf("Encrypted text: %s\n", text);

    return 0;
}
