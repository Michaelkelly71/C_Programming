#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        if (base == 'A') dna[i] = islower(dna[i]) ? 't' : 'T';
        else if (base == 'T') dna[i] = islower(dna[i]) ? 'a' : 'A';
        else if (base == 'C') dna[i] = islower(dna[i]) ? 'g' : 'G';
        else if (base == 'G') dna[i] = islower(dna[i]) ? 'c' : 'C';
    }

    printf("Complement: %s\n", dna);
    return 0;
}
