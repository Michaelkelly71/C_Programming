#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    
    // Remove newline character if present
    dna[strcspn(dna, "\n")] = '\0';
    
    for (int i = 0; i < strlen(dna); i++) {
        char c = toupper(dna[i]);
        
        switch (c) {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
            default:
                // Handle invalid characters if needed
                break;
        }
        
        // Preserve original case (bonus)
        if (islower(dna[i])) {
            dna[i] = tolower(dna[i]);
        }
    }
    
    printf("Complement: %s\n", dna);
    return 0;
}