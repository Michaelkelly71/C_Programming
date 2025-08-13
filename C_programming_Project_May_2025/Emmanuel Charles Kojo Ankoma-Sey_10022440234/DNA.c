#include <stdio.h>
#include <string.h>

void DNA_complement(char *dna, char *complement) {
    int i;
    for (i = 0; dna[i] != '\0'; i++) {
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
                complement[i] = dna[i]; // Unknown base
        }
    }
    complement[i] = '\0'; // Null-terminate the complement string
}

int main(){
    char dna[50], complement[50];

    printf("Enter a DNA sequence:");
    scanf("%s", dna);

    DNA_complement(dna, complement);
    printf("Complement: %s\n", complement);

    return 0;
}