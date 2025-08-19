//PROGRAMMING IN C PRACTICAL EXAM

//QUESTION - READABILITY ANALYZER

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void) {
    char text[1000];
    printf("Text:");
    fgets(text,sizeof(text),stdin);

    int letters= 0 , words = 1, sentences = 0;

    for (int i=0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            letters++;
        } else if (text[i] == ' ') {
            words++;
        } else if (text[i] == '.' || text[i] == '!' || text[i]== '?') {

        }
    }
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences/ words) * 100;

    float index = 0.0588 * L- 0.296 * S - 15.8;
    int grade = round(index) ;

    if (grade<1) {
        printf("Before Grade 1\n");
    } else if ( grade>=16) {
        printf("Grade 16+ \n");
    } else {
        printf("Grade %d\n", grade);
    }
     return 0;
}

// QUESTION  DNA COMPLEMENT GENERATOR

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char dna[1000];
    printf("Enter a DNA sequence:");
    scanf("%s", dna);

    printf("Complement: ");
    for(int i=0; dna[i] != '\0' ; i++) {
        char base = dna[i];
        switch (toupper(base)) {
            case 'A':
             putchar((islower(base)) ? 't' : 'T');
             break;
            case 'T':
             putchar((islower(base)) ? 'a' : 'A');
             break;
            case 'C' :
             putchar((islower(base)) ? 'g' : 'G');
             break;
            case 'G':
             putchar((islower(base)) ? 'c' : 'C');
             break;
            default :
             putchar(base) ; 

        }
    }
    printf("\n");

    return 0;
        

            

}

// //QUESTION - CAESAR CIPHER ENCRYPTION

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char plaintext[1000];
    int key;

    printf("Enter key(number of shifts) :");
    scanf("%d", &key);
    getchar();

    printf("plaintext: ");
    fgets(plaintext , sizeof(plaintext), stdin);

    printf("ciphertext :");
    for(int i= 0; plaintext[i]!= '\0'; i++) {
        char c= plaintext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A': 'a' ;
            putchar(((c- base + key)% 26) +base );
        } else {
            putchar(c) ;
        }
    } 
    printf("\n");

    return 0;
}


