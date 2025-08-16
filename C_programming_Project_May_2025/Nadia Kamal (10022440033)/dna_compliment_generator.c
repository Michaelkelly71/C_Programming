#include <stdio.h>
#include <ctype.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence:\n");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        switch (base) {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
            default:
                // invalid character handling
                dna[i] = '?';
                break;
        }
    }

    printf("Complement: %s\n", dna);

    return 0;
}
