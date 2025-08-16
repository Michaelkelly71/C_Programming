#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    
    int key = atoi(argv[1]) % 26;
    char text[1000];
    
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Cipher: ");
    for (int i = 0; text[i]; i++) {
        if (isupper(text[i])) putchar('A' + (text[i] - 'A' + key) % 26);
        else if (islower(text[i])) putchar('a' + (text[i] - 'a' + key) % 26);
        else putchar(text[i]);
    }
    
    return 0;
}