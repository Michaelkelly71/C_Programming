#include <stdio.h>
#include <ctype.h>  

int main() {
    char plaintext[1000];
    int key;


    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin); 

    
    printf("Enter key (number of shifts): ");
    scanf("%d", &key);

    
    key = key % 26;

    
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isupper(c)) {
        
            c = (c - 'A' + key) % 26 + 'A';
        }
        else if (islower(c)) {
            
            c = (c - 'a' + key) % 26 + 'a';
        }
        

        printf("%c", c);
    }
    printf("\n");

    return 0;  
}
