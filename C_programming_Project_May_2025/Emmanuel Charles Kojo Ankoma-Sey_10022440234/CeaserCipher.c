#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ceaserCipher(const char *plaintext, int key, char *ciphertext){
    int i;
    for (i = 0; plaintext[i] != '\0'; i++){
       char c  = plaintext[i];
       if (isupper(c))
        ciphertext[i] = (c - 'A' + key) % 26 + 'A';
       else if (islower(c))                                             
        ciphertext[i] = (c - 'a' + key) % 26 + 'a';
       else
        ciphertext[i] = c; 
    }
    ciphertext[i] = '\0';
}

int main(){
    char plaintext[250], ciphertext[250];
    int key;

    printf("Enter a line of text: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter a key: \n");
    scanf("%d", &key);
    
    ceaserCipher(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}