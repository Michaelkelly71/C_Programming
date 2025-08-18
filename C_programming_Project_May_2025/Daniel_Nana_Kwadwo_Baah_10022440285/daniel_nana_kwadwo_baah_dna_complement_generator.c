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
            case 'A': putchar('T'); break;
            case 'T': putchar('A'); break;
            case 'C': putchar('G'); break;
            case 'G': putchar('C'); break;
            default: putchar(base); // in case of invalid char
        }
    }
    printf("\n");
    return 0;
}
