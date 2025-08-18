#include <stdio.h>

int main() {
    char text[1000];
    int key;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (number to shift): ");
    scanf("%d", &key);

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        
        if (c >= 'A' && c <= 'Z') {
            int p_i = c - 'A';           
            int c_i = (p_i + key) % 26;  
            c = c_i + 'A';               
        }

        
        else if (c >= 'a' && c <= 'z') {
            int p_i = c - 'a';           
            int c_i = (p_i + key) % 26;   
            c = c_i + 'a';                
        }

        text[i] = c;  
    }

    printf("Encrypted text: %s\n", text);
    return 0;
}
