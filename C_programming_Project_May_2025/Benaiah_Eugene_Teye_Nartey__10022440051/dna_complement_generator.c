#include <stdio.h>


char get_complement(char base) {
    switch (base) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'a': return 't';
        case 't': return 'a';
        case 'c': return 'g';
        case 'g': return 'c';
        default:  return '?';  
    }
}

int main() {
    char dna[1000];  

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);  

    printf("Complement: ");

    
    for (int i = 0; dna[i] != '\0'; i++) {
        printf("%c", get_complement(dna[i]));
    }

    printf("\n");
    return 0;
}
