#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main(){
    char text[1000];
    printf("Enter you text: ");
    fgets(text,sizeof(text),stdin);
    int length=strlen(text), letters=0, words=1, sentences=0 ;
    for(int i=0; i<length; i++){
        if(isalpha(text[i])){
            letters++;
        }if(text[i]==' '){
            words++;
        }if(text[i]=='.'|| text[i]=="!"|| text[i]=="?"){
            sentences++;
        }
    }
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if(index < 1) {
        printf("Before Grade 1\n");
    }else if(index >= 16) {
        printf("Grade 16+\n");
    }else{
        printf("Grade %d\n", index);
    } 
    return 0;
}
