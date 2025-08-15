#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        switch (base) {
            case 'A': putchar('T'); break;
            case 'T': putchar('A'); break;
            case 'C': putchar('G'); break;
            case 'G': putchar('C'); break;
            default: putchar('?'); // Invalid base
        }
    }
    printf("\n");
    return 0;
}
