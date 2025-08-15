#include <stdio.h>
#include <ctype.h>

char get_complement(char base) {
    switch (toupper(base)) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        default: return base;
    }
}

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char comp = get_complement(dna[i]);
        if (islower(dna[i]))
            comp = tolower(comp);
        else
            comp = toupper(comp);
        printf("%c", comp);
    }
    printf("\n");

    return 0;
}


