#include <stdio.h>
#include <string.h>

char get_complement(char base);

int main() {
    char dna[1000];

    // Prompt user for DNA input
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);

    // Remove newline character if present
    size_t len = strlen(dna);
    if (dna[len - 1] == '\n') {
        dna[len - 1] = '\0';
    }

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char complement = get_complement(dna[i]);
        if (complement != '\0') {
            printf("%c", complement);
        } else {
            // Handle invalid characters gracefully
            printf("?");
        }
    }
    printf("\n");

    return 0;
}

// Function to return the complementary DNA base
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
        default: return '\0'; // Invalid base
    }
}
