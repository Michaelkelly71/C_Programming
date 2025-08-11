#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main(){
    char sentence [1000];
    int cletters = 0, cwords = 1, csentence= 0;
    double avg_l,avg_sentence,score;

    printf ("Enter any text: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int j=0; sentence[j]!= '\0'; j++){
        if (isalpha (sentence[j])){
            cletters++;
        }
        if (sentence [j]==' '){
            cwords++;
        }
        if (sentence[j]=='.'|| sentence[j]=='!' || sentence[j]=='?'){
            csentence++;    
        }
        }    
        avg_l = ((double)cletters / cwords)* 100;
        avg_sentence = ((double)csentence / cwords) * 100;

        score = 0.0588 * avg_l - 0.296 * avg_sentence - 15.8;
        int gradelevel = round(score);

        if (gradelevel<1){
            printf("Before grade 1\n");
        }else if (gradelevel>=16){
           printf("Grade 16+\n");
        }else{
            printf("Grade %d\n", gradelevel);
        }
    
    
        return 0;
}