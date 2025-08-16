#include <stdio.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A' || dna[i] == 'a') dna[i] = 'T';
        else if (dna[i] == 'T' || dna[i] == 't') dna[i] = 'A';
        else if (dna[i] == 'C' || dna[i] == 'c') dna[i] = 'G';
        else if (dna[i] == 'G' || dna[i] == 'g') dna[i] = 'C';
    }

    printf("Complement: %s\n", dna);
    return 0;
}
