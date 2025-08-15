#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char message[1000];
    int shift;

    printf("Shift value (key): ");
    scanf("%d", &shift);
    getchar(); 

    printf("Enter text to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Encrypted text: ");
    int idx = 0;
    while (message[idx] != '\0') {
        char current = message[idx];

        if (isalpha(current)) {
            char start = (isupper(current)) ? 'A' : 'a';
            current = ((current - start + shift) % 26) + start;
        }
        
        putchar(current);
        idx++;
    }

    printf("\n");
    return 0;
}
