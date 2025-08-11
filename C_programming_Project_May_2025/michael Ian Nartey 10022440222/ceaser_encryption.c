#include <stdio.h>
#include <ctype.h>

int main() {
    char plain[500];
    int shiftValue;

    printf("Enter message: ");
    fgets(plain, sizeof(plain), stdin);

    printf("Enter key (number): ");
    scanf("%d", &shiftValue);

    for (int k = 0; plain[k] != '\0'; k++) {
        if (isalpha(plain[k])) {
            char start = isupper(plain[k]) ? 'A' : 'a';
            plain[k] = (plain[k] - start + shiftValue) % 26 + start;
        }
    }

    printf("Encrypted text: %s\n", plain);
    return 0;
}
