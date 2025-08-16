#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[50];
    printf("Enter your DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    
    
    dna[strcspn(dna, "\n")] = '\0';
    
    for (int i = 0; i < strlen(dna); i++) {
        char new_dna = dna[i];
        if (isupper(new_dna)) {
            switch (new_dna) {
                case 'A': dna[i] = 'T'; break;
                case 'T': dna[i] = 'A'; break;
                case 'C': dna[i] = 'G'; break;
                case 'G': dna[i] = 'C'; break;
            }
        } else if (islower(new_dna)) {
            switch (new_dna) {
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
