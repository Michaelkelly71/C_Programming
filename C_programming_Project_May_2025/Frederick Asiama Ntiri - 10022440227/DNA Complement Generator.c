#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generate_complement(char dna[]) {
    for (int i = 0; dna[i] != '\0'; i++) {
        char c = dna[i];
        if (isupper(c)) {
            switch (c) {
                case 'A': dna[i] = 'T'; break;
                case 'T': dna[i] = 'A'; break;
                case 'C': dna[i] = 'G'; break;
                case 'G': dna[i] = 'C'; break;
            }
        } else if (islower(c)) {
            switch (c) {
                case 'a': dna[i] = 't'; break;
                case 't': dna[i] = 'a'; break;
                case 'c': dna[i] = 'g'; break;
                case 'g': dna[i] = 'c'; break;
            }
        }
    }
}

int main() {
    char dna[100];
    
    printf("Enter a DNA sequence: ");
    scanf("%99s", dna);  
    generate_complement(dna);
    
    printf("Complement: %s\n", dna);
    
    return 0;
}