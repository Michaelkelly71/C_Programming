#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(const char *text ) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++){
        if (isalpha(text[i])){
            count ++;
        }
    }
    return count;
}

// count words:
int count_words(const char *text){
    int count = 0;

    // check for empty string
    if  (text[0] == '\0'){
        return 0;
    }

    // counting the first word
    if (text[0] != '\0' && text[0] != '\n'){
        count = 1;
    }

    for (int i = 0; text[i] != '\0'; i++){
        if (isspace(text[i] && i>0) && !isspace(text[i-1])){
            count++;
        }
    }
    return count;
}

// count sentectes
int count_sentences(const char *text){
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '.' || text[i] == '?' || text[i] == '!'){
            count ++;
        } 
    }
    return count;
}

int main(){
    char text[1000];
    printf("Enter Text: \n");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the L and S
    // check if words>0 to avoid dividing by zero
    float L = 0;
    float S = 0;

    if (words > 0) {
        L = ((float)letters / words) * 100;
        S = ((float)sentences / words) * 100;
    }
    
    // Apply the Coeman_Liau formula to calculate index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Calculate and print grade
    if (index < 1){
        printf("Before Grade 1.\n");
    }else if(index >=16){
        printf("Grade 16+.\n");
    }else{
        printf("Grade %d.\n", index);
    }


    return 0;
}
