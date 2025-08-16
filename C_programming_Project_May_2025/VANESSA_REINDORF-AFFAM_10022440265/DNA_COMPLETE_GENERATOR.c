#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        if (base == 'A') dna[i] = 'T';
        else if (base == 'T') dna[i] = 'A';
        else if (base == 'C') dna[i] = 'G';
        else if (base == 'G') dna[i] = 'C';
        else dna[i] = base; // if invalid character, leave as is
    }

    printf("Complement: %s\n", dna);
    return 0;
}

