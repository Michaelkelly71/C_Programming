#include <stdio.h>
#include <string.h>

int main() {

    char dna[100]; 
    printf("Enter a DNA sequence:\n");
    fgets(dna, sizeof(dna), stdin); 

    size_t len = strlen(dna);
    if (len > 0 && dna[len - 1] == '\n') {
        dna[len - 1] = '\0';
    }

    char complement[100];
    
    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A':
            case 'a':
                complement[i] = 'T';
                break;
            case 'T':
            case 't':
                complement[i] = 'A';
                break;
            case 'C':
            case 'c':
                complement[i] = 'G';
                break;
            case 'G':
            case 'g':
                complement[i] = 'C';
                break;
            default:
                
                printf("Invalid character '%c' in DNA sequence.\n", dna[i]);
                return 1; 
        }
    }
    
   
    complement[strlen(dna)] = '\0';

   
    printf("Complement: %s\n", complement);

    return 0;
}
