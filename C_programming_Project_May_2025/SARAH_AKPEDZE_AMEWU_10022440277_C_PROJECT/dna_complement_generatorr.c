#include <stdio.h>
#include <string.h>

int main() {
    char dna[1000], complement[1000];
    
    printf("Enter a DNA sequence: ");
    if (fgets(dna, sizeof(dna), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline from fgets
    dna[strcspn(dna, "\n")] = '\0';

    for (int i = 0; dna[i] != '\0'; i++) {
        char base = dna[i];
        switch (base) {
            case 'A': complement[i] = 'T'; break;
            case 'T': complement[i] = 'A'; break;
            case 'C': complement[i] = 'G'; break;
            case 'G': complement[i] = 'C'; break;
            case 'a': complement[i] = 't'; break;
            case 't': complement[i] = 'a'; break;
            case 'c': complement[i] = 'g'; break;
            case 'g': complement[i] = 'c'; break;
            default:  complement[i] = base; // leave unchanged if invalid char
        }
    }

    complement[strlen(dna)] = '\0'; // null-terminate
    printf("Complement: %s\n", complement);

    return 0;
}
