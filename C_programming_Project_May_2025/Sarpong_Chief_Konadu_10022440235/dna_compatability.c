#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char dna[1000], complement[1000];
    
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    
    // Remove newline character
    dna[strcspn(dna, "\n")] = '\0';
    
    for (int i = 0; i < strlen(dna); i++) {
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
                complement[i] = dna[i]; // Keep invalid characters as-is
        }
        
        // Preserve original case (bonus)
        if (islower(dna[i])) {
            complement[i] = tolower(complement[i]);
        }
    }
    
    complement[strlen(dna)] = '\0';
    
    printf("Complement: %s\n", complement);
    return 0;
}
