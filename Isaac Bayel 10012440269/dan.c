#include <stdio.h>
#include <string.h>

int main() {
    char dna[1000];

    // Ask user for DNA sequence
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A' || dna[i] == 'a') {
            printf("T");
        } else if (dna[i] == 'T' || dna[i] == 't') {
            printf("A");
        } else if (dna[i] == 'C' || dna[i] == 'c') {
            printf("G");
        } else if (dna[i] == 'G' || dna[i] == 'g') {
            printf("C");
        }
    }
    printf("\n");
    return 0;
}
