#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pltext[1000];
    int key; // Caesar cipher key

    printf("plaintext: ");
    fgets(pltext, sizeof(pltext), stdin);

    printf("Key: ");
    scanf("%d", &key);

    size_t length = strlen(pltext);
    if (length > 0 && pltext[length - 1] == '\n'){
        pltext[length -1] = '\0';
        length--;
    }

    for (int i = 0; i < length; i++){
        if (isupper(pltext[i])){
            pltext[i] = ((pltext[i]- 'A' + key) % 26 + 'A');   
        } else if (islower(pltext[i])){
            pltext[i] = ((pltext[i]- 'a' + key) % 26 + 'a');
        }    
    }

    printf("ciphertext: %s\n", pltext);
    return 0;
}