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
    int length=strlen(plaintext);
    for(int i=0; i<length; i++){
        char ch=plaintext[i];
        if(isupper(ch)){
            printf("%c", ((ch - 'A' + key) % 26) + 'A');
        }else if(islower(ch)){
            printf("%c", ((ch - 'a' + key) % 26) + 'a');
        }else{
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
