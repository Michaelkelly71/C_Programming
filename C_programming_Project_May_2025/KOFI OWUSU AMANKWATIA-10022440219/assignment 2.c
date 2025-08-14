#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000];

    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);

    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]); // handle lowercase
        if (base == 'A') {
            dna[i] = 'T';
        } else if (base == 'T') {
            dna[i] = 'A';
        } else if (base == 'C') {
            dna[i] = 'G';
        } else if (base == 'G') {
            dna[i] = 'C';
        }
        // leave non-DNA chars (like newline) as is
    }

    printf("Complement: %s", dna);
    return 0;
}
