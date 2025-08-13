//AMDAWAY MUNIR BAMBA-10022440301
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char text[100];
    int key;

    printf("Enter the key:\n");
    printf("->");
    scanf("%d", &key);
    getchar();

    printf("Enter the plain text:\n");
    printf("->");
    fgets(text, 100, stdin);

    for(int i = 0; text[i] != '\0'; i++){
        char cipher = text[i];

        if(isupper(cipher)){
            cipher = ((cipher - 'A' + key) % 26) + 'A';
        }

        else if (islower(cipher)) {
            cipher = ((cipher - 'a' + key) % 26) + 'a';
        }

        printf("%c", cipher);
    }

    return 0;
}