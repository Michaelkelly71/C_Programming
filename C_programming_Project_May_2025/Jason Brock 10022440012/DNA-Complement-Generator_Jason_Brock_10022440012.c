#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    char dna[1000];
    char complement[1000];
    

    printf("Enter a DNA sequence:\n");
    scanf("%s", dna);  

    for (int i = 0; i < strlen(dna); i++) {
        

        switch (dna[i]) {
            case 'A':
                complement[i] = 'T';
                break;
            case 'T':
                complement[i] = 'A';
                break;
            case 'C':
                complement[i] = 'G';
                break;
            case 'G':
                complement[i] = 'C';
                break;
            case 'a':
                complement[i] = 't';
                break;
            case 't':
                complement[i] = 'a';
                break;
            case 'c':
                complement[i] = 'g';
                break;
            case 'g':
                complement[i] = 'c';
                break;
            default:
                complement[i] = '?';  
                break;
        }
    }

    complement[strlen(dna)] = '\0'; 

    printf("Complement: %s\n", complement);

    return 0;
}
