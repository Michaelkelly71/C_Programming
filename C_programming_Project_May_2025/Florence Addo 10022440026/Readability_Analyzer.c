#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define Index 0.0588 * L - 0.296 * S - 15.8

int main(){
    char block_of_text[1000];
    double letters = 0, words = 1, sentences = 0;
    double L = (letters / words) * 100, S =(sentences / words) * 100;

    printf("Enter a block of English text:\n");
    fgets(block_of_text, 1000, stdin);

    for(int i = 0; block_of_text[i] != '\0'; i++){
        if(isalpha(block_of_text[i])){
            letters++;
        }

        else if(block_of_text[i] == ' '){
            words++;
        }

        else if(block_of_text[i] == '.' || block_of_text[i] == '!' || block_of_text[i] == '?'){
            sentences++;
        }
    }

    int grade = round(Index);

    if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
