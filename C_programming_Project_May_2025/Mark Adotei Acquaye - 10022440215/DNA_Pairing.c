#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char strand[1000];
    printf("Enter DNA strand: ");
    scanf("%s", strand);

    printf("Base Pairing: ");
    for (int j = 0; strand[j] != '\0'; j++) {
        char nucleotide = toupper(strand[j]);
        if (nucleotide == 'A') {
            putchar('T');
        } else if (nucleotide == 'T') {
            putchar('A');
        } else if (nucleotide == 'C') {
            putchar('G');
        } else if (nucleotide == 'G') {
            putchar('C');
        } else {
            putchar('X'); // Invalid character marker
        }
    }
    printf("\n");
    return 0;
}