//David Akanni
#include <stdio.h>
#include <ctype.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = dna[i];
        switch (toupper(base)) {
            case 'A': putchar(islower(base) ? 't' : 'T'); break;
            case 'T': putchar(islower(base) ? 'a' : 'A'); break;
            case 'C': putchar(islower(base) ? 'g' : 'G'); break;
            case 'G': putchar(islower(base) ? 'c' : 'C'); break;
            default: putchar(base); // For invalid characters
        }
    }
    printf("\n");
    return 0;
}