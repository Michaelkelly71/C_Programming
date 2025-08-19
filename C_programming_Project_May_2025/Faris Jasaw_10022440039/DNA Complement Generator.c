#include <stdio.h>
#include <ctype.h>

int main(void) {
    char dna[1000];

  
    printf("Enter a DNA sequence: ");
    if (!fgets(dna, sizeof(dna), stdin)) {
        return 0;
    }

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        char c = dna[i];
     
        if (c == 'A')      putchar('T');
        else if (c == 'T') putchar('A');
        else if (c == 'C') putchar('G');
        else if (c == 'G') putchar('C');
 
        else if (c == 'a') putchar('t');
        else if (c == 't') putchar('a');
        else if (c == 'c') putchar('g');
        else if (c == 'g') putchar('c');
        
        else               putchar(c);
    }

    return 0;
}
