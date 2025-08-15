#include <stdio.h>
#include <ctype.h>

int main(void) {
    char dna_sequence[1000];
    
    printf("Enter a DNA sequence: ");
    scanf("%s", dna_sequence);

    for (int i = 0; dna_sequence[i] != '\0'; i++) {
        char current_base = toupper(dna_sequence[i]); 
        
        switch (current_base) {
            case 'A': 
                dna_sequence[i] = islower(dna_sequence[i]) ? 't' : 'T'; 
                break;
            case 'T': 
                dna_sequence[i] = islower(dna_sequence[i]) ? 'a' : 'A'; 
                break;
            case 'C': 
                dna_sequence[i] = islower(dna_sequence[i]) ? 'g' : 'G'; 
                break;
            case 'G': 
                dna_sequence[i] = islower(dna_sequence[i]) ? 'c' : 'C'; 
                break;
            default: 
                break; 
        }
    }

    printf("Complement: %s\n", dna_sequence);
    return 0;
}