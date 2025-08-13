//AMDAWAY MUNIR BAMBA-10022440301
#include <stdio.h>
#include <string.h>

int main(){
    char dna[5];

    printf("Enter a DNA sequence:\n");
    printf("->");
    fgets(dna, 5, stdin);

    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A': dna[i] = 'T'; break;
            case 'T': dna[i] = 'A'; break;
            case 'C': dna[i] = 'G'; break;
            case 'G': dna[i] = 'C'; break;
            case 'a': dna[i] = 't'; break;
            case 't': dna[i] = 'a'; break;
            case 'c': dna[i] = 'g'; break;
            case 'g': dna[i] = 'c'; break;
            default:  break; 
        }
    }

    printf("Complement: %s\n", dna);

    return 0;
}