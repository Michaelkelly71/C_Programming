#include <stdio.h>

int main() {
    char dna[1000];
    
    printf("Enter DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    
    printf("Complement: ");
    
    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A') putchar('T');
        else if (dna[i] == 'T') putchar('A');
        else if (dna[i] == 'C') putchar('G');
        else if (dna[i] == 'G') putchar('C');
        else if (dna[i] == 'a') putchar('t');
        else if (dna[i] == 't') putchar('a');
        else if (dna[i] == 'c') putchar('g');
        else if (dna[i] == 'g') putchar('c');
        else putchar(dna[i]);
    }
    
    return 0;
}