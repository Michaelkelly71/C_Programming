#include <stdio.h>
#include <ctype.h>

int main() {
    char dna[100];
    
    printf("Enter a DNA sequence: ");
    scanf("%99s", dna);
    
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = dna[i];
        
        if (base == 'A') dna[i] = 'T';
        else if (base == 'T') dna[i] = 'A';
        else if (base == 'C') dna[i] = 'G';
        else if (base == 'G') dna[i] = 'C';
        else if (base == 'a') dna[i] = 't';
        else if (base == 't') dna[i] = 'a';
        else if (base == 'c') dna[i] = 'g';
        else if (base == 'g') dna[i] = 'c';
    }
    
    printf("Complement: %s\n", dna);
    
    return 0;
}