#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    char plaintext[1000], ciphertext[1000];
    int key;


    printf("Enter key (shift vakue): ");
    scanf("%d", &key);
    getchar();


    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (int i = 0; plaintext[i] != '\0'; i++){
        char ch =plaintext[i];
        if (isalpha(ch)){
            char base = isupper(ch) ? 'A' :'a';
            ciphertext[i] = (ch - base + key) % 26 + base;    
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n" ,ciphertext);
    return 0;
}
