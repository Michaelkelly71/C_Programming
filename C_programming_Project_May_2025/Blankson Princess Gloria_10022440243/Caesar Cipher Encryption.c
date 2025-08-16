#include <stdio.h>
#include <ctype.h> 
#include <string.h>



int main() {
    char plaintext[2500];
    char ciphertext[2500];
    int key;

    printf("Plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Key: \n");
    scanf("%d", &key);

    key = key % 26;

    int lenght = strlen(plaintext);
    for (int i = 0; i < lenght; i++) {
        char c = plaintext[i];

        if(isupper(c)) {
            ciphertext[i] = ((c - 'A' + key) % 26) + 'A';
        }
        else if (islower(c)) {
            ciphertext[i] = ((c - 'a' + key) % 26) + 'a';
        }
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[lenght]= '\0';

    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}