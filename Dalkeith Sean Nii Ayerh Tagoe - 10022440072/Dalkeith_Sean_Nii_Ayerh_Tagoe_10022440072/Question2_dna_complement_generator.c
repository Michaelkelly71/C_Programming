// Question 2 - DNA Complement generator

#include <stdio.h>

static char complement_base(char c) {
    switch (c) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'a': return 't';
        case 't': return 'a';
        case 'c': return 'g';
        case 'g': return 'c';
        default:  return c; // leave any other character unchanged
    }
}

int main(void) {
    char seq[10000];

    printf("Enter a DNA sequence: ");
    if (!fgets(seq, sizeof(seq), stdin)) return 1;

    for (int i = 0; seq[i] != '\0'; i++) {
        seq[i] = complement_base(seq[i]);
    }

    printf("Complement: %s", seq);
    return 0;
}