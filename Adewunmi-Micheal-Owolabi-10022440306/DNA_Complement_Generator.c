#include <stdio.h>

int main() {
    char dna[1000], complement[1000];
    printf("Enter DNA sequence (A, T, C, G): ");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A': complement[i] = 'T'; break;
            case 'T': complement[i] = 'A'; break;
            case 'C': complement[i] = 'G'; break;
            case 'G': complement[i] = 'C'; break;
            default: complement[i] = 'N'; // N for invalid
        }
    }
    complement[strlen(dna)] = '\0';

    printf("Complementary DNA: %s\n", complement);

    return 0;
}
