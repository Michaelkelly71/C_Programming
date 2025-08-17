// dna_complement.c
#include <stdio.h>
#include <ctype.h>

static char comp_base(char c) {
    switch (c) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'a': return 't';
        case 't': return 'a';
        case 'c': return 'g';
        case 'g': return 'c';
        default:  return c; // passthrough for unexpected chars
    }
}

int main(void) {
    char s[10000];

    printf("Enter a DNA sequence: ");
    if (!fgets(s, sizeof(s), stdin)) return 1;

    printf("Complement: ");
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(comp_base(s[i]));
    }
    return 0;
}
