#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int letterFind(char text[]){
    int countL=0;
    for(int i=0;i<(strlen(text));i++){
        if (isalpha(text[i])){
            countL++;
        }
    }
    return countL;
}

int wordFind(char text[]){
    int countW=1;
    for( int i=0;i<(strlen(text));i++){
        if (text[i]==' '){
            countW++;
        }
    }
    return countW;
}

int sentenceFind(char text[]){
    int countS=0;
    for( int i=0;i<(strlen(text));i++){
        if (text[i]=='.'|| text[i]=='!'|| text[i]=='?'){
            countS++;
        }
    }
    return countS;
}



int main(){
    char  text[5000];

    printf("Text:\n");
    fgets(text, sizeof(text), stdin);

    int letters=letterFind(text);
    int  words=wordFind(text);
    int sent=sentenceFind(text);

    float L = ((float)letters/words) * 100;
    float S = ((float)sent/words) *100;
    
    float Index = 0.0588 * L - 0.296 * S - 15.8;

    if (Index<1){
        printf("Before Grade 1 \n");
    }
    else if (Index >= 16){
            printf("Grade 16+\n");
    }else{
        printf("Grade %.0f\n", round(Index));
    }



    return 0;
}