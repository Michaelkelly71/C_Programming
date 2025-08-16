#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000];

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = dna[i];
        switch (toupper(base)) {
            case 'A': printf("T"); break;
            case 'T': printf("A"); break;
            case 'C': printf("G"); break;
            case 'G': printf("C"); break;
            default: printf("N"); // handles invalid bases
        }
    }
    printf("\n");

    return 0;
}
