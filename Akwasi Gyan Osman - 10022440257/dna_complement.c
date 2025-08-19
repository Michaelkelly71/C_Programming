#include <stdio.h>

int main(void) {
    char dna[2000];
    printf("Enter a DNA sequence: ");
    if (scanf("%1999s", dna) != 1) return 0;

    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A': dna[i] = 'T'; break;
            case 'T': dna[i] = 'A'; break;
            case 'C': dna[i] = 'G'; break;
            case 'G': dna[i] = 'C'; break;
            case 'a': dna[i] = 't'; break;
            case 't': dna[i] = 'a'; break;
            case 'c': dna[i] = 'g'; break;
            case 'g': dna[i] = 'c'; break;
            default: /* ignore other chars */ break;
        }
    }
    printf("Complement: %s\n", dna);
    return 0;
}
