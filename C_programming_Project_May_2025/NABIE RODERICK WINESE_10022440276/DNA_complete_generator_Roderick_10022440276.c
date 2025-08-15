#include <stdio.h>

int main() {
    char dna[1000];
    int i;

    
    printf("Enter a DNA sequence: ");
    scanf("%s", dna); 

    
    for (i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A') {
            dna[i] = 'T';
        } else if (dna[i] == 'T') {
            dna[i] = 'A';
        } else if (dna[i] == 'C') {
            dna[i] = 'G';
        } else if (dna[i] == 'G') {
            dna[i] = 'C';
        } else if (dna[i] == 'a') {
            dna[i] = 't';
        } else if (dna[i] == 't') {
            dna[i] = 'a';
        } else if (dna[i] == 'c') {
            dna[i] = 'g';
        } else if (dna[i] == 'g') {
            dna[i] = 'c';
        }
    }

    
    printf("Complement: %s\n", dna);

    return 0;
}
