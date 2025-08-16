#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char plaintext[1000];
    int key;
    printf("Enter you key: ");
    scanf("%d",&key);
    getchar();
    printf("Enter the plaintext: ");
    fgets(plaintext,sizeof(plaintext),stdin);
    printf("The equivalent cyphertext is: ");
    int lenght=len(plaintext);
    for(int i=0; i<plaintext; i++){
        char ch=plaintext[i];
        if (isupper(ch)){
            printf("%c\n", ((ch - 'A' + key) % 26) + 'A');
        }else if(islower(ch)){
            printf("%c\n", ((ch - 'a' + key) % 26) + 'a');
        }else{
            printf("%c\n", ch);
        }
    }
    return 0;
}