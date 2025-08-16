 #include <stdio.h>
#include <ctype.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        if (base == 'A') putchar('T');
        else if (base == 'T') putchar('A');
        else if (base == 'C') putchar('G');
        else if (base == 'G') putchar('C');
        else putchar(base); 
    }
    printf("\n");
return 0;
}