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
            case 'A': printf("%c", islower(base) ? 't' : 'T'); break;
            case 'T': printf("%c", islower(base) ? 'a' : 'A'); break;
            case 'C': printf("%c", islower(base) ? 'g' : 'G'); break;
            case 'G': printf("%c", islower(base) ? 'c' : 'C'); break;
            default: printf("%c", base); 
        }
    }
    printf("\n");
    return 0;
}