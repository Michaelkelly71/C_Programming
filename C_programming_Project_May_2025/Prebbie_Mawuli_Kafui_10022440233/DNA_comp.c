#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SEQUENCE 1000

char get_complement_base(char nucleotide) {
    switch(toupper(nucleotide)) {
        case 'A': return (isupper(nucleotide) ? 'T' : 't');
        case 'T': return (isupper(nucleotide) ? 'A' : 'a');
        case 'C': return (isupper(nucleotide) ? 'G' : 'g');
        case 'G': return (isupper(nucleotide) ? 'C' : 'c');
        default: return nucleotide;
    }
}

void generate_complement_sequence(const char *sequence) {
    for (size_t i = 0; sequence[i] != '\0'; i++) {
        putchar(get_complement_base(sequence[i]));
    }
}

int main() {
    char dna_sequence[MAX_SEQUENCE];
    
    printf("Input DNA strand: ");
    if (fgets(dna_sequence, sizeof(dna_sequence), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    dna_sequence[strcspn(dna_sequence, "\n")] = '\0';
    
    printf("Complement strand: ");
    generate_complement_sequence(dna_sequence);
    putchar('\n');
    
    return 0;
}