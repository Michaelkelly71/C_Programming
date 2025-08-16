#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int key;
    
    printf("Input text: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    
    key = key % 26;
    if (key < 0) key += 26;
    
    int length = strlen(text);
    
    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (isupper(c)) {
            text[i] = ((c - 'A' + key) % 26) + 'A';
        } else if (islower(c)) {
            text[i] = ((c - 'a' + key) % 26) + 'a';
        }
    }
    
    printf("ciphertext: %s", text);
    return 0;
}