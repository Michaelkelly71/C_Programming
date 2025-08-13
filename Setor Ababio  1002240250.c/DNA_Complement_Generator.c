#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);
    dna[strcspn(dna, "\n")] = '\0'; 

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char c = toupper(dna[i]);
        if (c == 'A') putchar('T');
        else if (c == 'T') putchar('A');
        else if (c == 'C') putchar('G');
        else if (c == 'G') putchar('C');
        else putchar(dna[i]); 
    }
    printf("\n");
    return 0;
}