#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(){
    char text[100];
    int key=1;

     
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    
    printf("Enter key: ");
    scanf("%d", &key);

    
    key = key % 26;

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];

        if (isupper(c)) {
            
            char encrypted = ((c - 'A' + key) % 26) + 'A';
            printf("%c", encrypted);
        } else if (islower(c)) {
            
            char encrypted = ((c - 'a' + key) % 26) + 'a';
            printf("%c", encrypted);
        } else {
            
            printf("%c", c);
        }
    }

    printf("\n");
        
          

    

    return 0;
}