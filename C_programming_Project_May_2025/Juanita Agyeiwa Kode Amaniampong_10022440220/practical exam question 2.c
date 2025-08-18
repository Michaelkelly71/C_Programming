#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    for (int i = 0; i < strlen(dna); i++) {
        char base = toupper(dna[i]);
        switch (base) {
            case 'A': dna[i] = 'T'; break;
            case 'T': dna[i] = 'A'; break;
            case 'C': dna[i] = 'G'; break;
            case 'G': dna[i] = 'C'; break;
            default: dna[i] = 'N'; 
        }
    }

    printf("Complement: %s\n", dna);
    return 0;
}
