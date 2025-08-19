#include <stdio.h>
#include <string.h>

char complement(char base) {
    switch (base) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'a': return 't';
        case 't': return 'a';
        case 'c': return 'g';
        case 'g': return 'c';
        default:  return base;
    }
}

int main(void) {
    char dna[1000], comp[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    dna[strcspn(dna, "\n")] = '\0';

    int len = strlen(dna);
    for (int i = 0; i < len; i++) {
        comp[i] = complement(dna[i]);
    }
    comp[len] = '\0';

    printf("Complement: %s\n", comp);
    return 0;
}
