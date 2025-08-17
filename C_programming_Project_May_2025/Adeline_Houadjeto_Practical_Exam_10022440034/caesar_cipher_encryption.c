#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int key = 3;  

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            ch = ch + key;
            if (ch > 'Z') {
                ch -= 26; 
            }
        }
        else if (islower(ch)) {
            ch = ch + key;
            if (ch > 'z') {
                ch -= 26; 
            }
        }

        printf("%c", ch);
    }

    return 0;
}
