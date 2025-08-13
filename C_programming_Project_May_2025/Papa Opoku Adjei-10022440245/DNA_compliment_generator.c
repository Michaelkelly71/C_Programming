#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000], complement[1000];

    printf("Enter DNA sequence: ");
    scanf("%s", dna); 

    int length = strlen(dna);

    for (int i = 0; i < length; i++) {
        char base = toupper(dna[i]); 

        switch (base) {
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
            default:
                printf("\nInvalid base '%c' found in DNA sequence!\n", base);
                return 1; 
        }
    }

    complement[length] = '\0'; 

    printf("Complementary DNA: %s\n", complement);

    return 0;
}
