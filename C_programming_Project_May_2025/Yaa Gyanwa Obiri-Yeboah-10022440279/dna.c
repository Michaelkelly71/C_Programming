#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    
    
    dna[strcspn(dna, "\n")] = '\0';
    
    int length = strlen(dna);
    
    for (int i = 0; i < length; i++) {
        char c = dna[i];
        if (isupper(c)) {
            switch(c) {
                case 'A': dna[i] = 'T'; break;
                case 'T': dna[i] = 'A'; break;
                case 'C': dna[i] = 'G'; break;
                case 'G': dna[i] = 'C'; break;
            }
        } else if (islower(c)) {
            switch(c) {
                case 'a': dna[i] = 't'; break;
                case 't': dna[i] = 'a'; break;
                case 'c': dna[i] = 'g'; break;
                case 'g': dna[i] = 'c'; break;
            }
        }
    }
    
    printf("Complement: %s\n", dna);
    return 0;
}