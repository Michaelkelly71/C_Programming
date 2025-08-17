#include <stdio.h>

int main() {
    char dna[100];
    int i = 0;

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    while (dna[i] != '\0') {
        char base = dna[i];
        if (base >= 'a' && base <= 'z') {
            base = base - 32; 
        }

        if (base == 'A') dna[i] = 'T';
        else if (base == 'T') dna[i] = 'A';
        else if (base == 'C') dna[i] = 'G';
        else if (base == 'G') dna[i] = 'C';

        i++;
    }
    printf("Complement: %s\n", dna);
    return 0;
}