#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s shift_value\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[1]) % 26;
    char message[1000];

    printf("Enter text: ");
    fgets(message, sizeof(message), stdin);

    printf("Encoded: ");
    for (int pos = 0; message[pos] != '\0'; pos++) {
        char ch = message[pos];
        if (isupper(ch)) {
            char enc = ((ch - 'A' + shift) % 26) + 'A';
            putchar(enc);
        } else if (islower(ch)) {
            char enc = ((ch - 'a' + shift) % 26) + 'a';
            putchar(enc);
        } else {
            putchar(ch);
        }
    }
    printf("\n");
    return 0;
}