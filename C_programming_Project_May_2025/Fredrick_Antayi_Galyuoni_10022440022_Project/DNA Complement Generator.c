//DNA Complement Generator
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char dna[200];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        switch (base) {
            case 'A': printf("T"); break;
            case 'T': printf("A"); break;
            case 'C': printf("G"); break;
            case 'G': printf("C"); break;
            default: printf("N"); // For invalid bases
        }
    }
    printf("\n");
    return 0;
}
