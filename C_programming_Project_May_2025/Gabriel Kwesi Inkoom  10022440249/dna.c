#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[50];
    printf("Enter your DNA sequence: ");
    fgets(dna, 50, stdin);
    
    
    dna[strcspn(dna, "\n")] = '\0';
    
    for (int i = 0; i < strlen(dna); i++) {
        char user_input = dna[i];
        if (isupper(user_input)) {
            switch (user_input) {
                case 'A': dna[i] = 'T'; break;
                case 'T': dna[i] = 'A'; break;
                case 'C': dna[i] = 'G'; break;
                case 'G': dna[i] = 'C'; break;
            }
        } else if (islower(user_input)) {
            switch (user_input) {
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