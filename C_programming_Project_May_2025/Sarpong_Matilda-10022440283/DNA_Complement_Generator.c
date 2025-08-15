#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);

    
    dna[strcspn(dna, "\n")] = '\0';

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = dna[i];
        switch (toupper(base)) {
            case 'A': putchar(isupper(base) ? 'T' : 't'); break;
            case 'T': putchar(isupper(base) ? 'A' : 'a'); break;
            case 'C': putchar(isupper(base) ? 'G' : 'g'); break;
            case 'G': putchar(isupper(base) ? 'C' : 'c'); break;
            default: putchar(base); 
        }
    }
    printf("\n");

    return 0;
}