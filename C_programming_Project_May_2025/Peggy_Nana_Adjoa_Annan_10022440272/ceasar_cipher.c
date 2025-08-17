#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char plaintext[1024];
    int key;

    // ask and read key
    printf("key: ");
    scanf("%d", &key);
    getchar();


    printf("Enter plain text:" );
    fgets(plaintext, sizeof(plaintext), stdin);

    char ciphertext[1024];
    int len = strlen(plaintext);

    for (int i = 0; i < len; i++){
        char current_char = plaintext[i];
        if(islower(current_char)){
            // lowercase formula
            ciphertext[i] = 'a' + ((current_char - 'a' +key) % 26);
        }else if(isupper(current_char)){
            // uppercase formula
            ciphertext[i] = 'A' + ((current_char - 'A' + key) % 26);
        }else{
            ciphertext[i] = current_char;
        }
    }

    ciphertext[len] = '\0';

    printf("ciphertext: %s\n", ciphertext);



    return 0;
}