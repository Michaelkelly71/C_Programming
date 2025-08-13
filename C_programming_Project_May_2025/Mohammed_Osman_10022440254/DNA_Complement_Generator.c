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
        if (base == 'A') printf("T");
        else if (base == 'T') printf("A");
        else if (base == 'C') printf("G");
        else if (base == 'G') printf("C");
        else if (base == 'a') printf("t");
        else if (base == 't') printf("a");
        else if (base == 'c') printf("g");
        else if (base == 'g') printf("c");
        else printf("%c", base); // ignore invalid
    }
    printf("\n");
    return 0;
}
