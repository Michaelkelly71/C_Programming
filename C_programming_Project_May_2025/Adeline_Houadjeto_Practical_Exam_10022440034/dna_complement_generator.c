#include <stdio.h>
#include <ctype.h>  

int main() {
    char seq[100];  

    printf("Enter a DNA sequence: ");
    scanf("%99s", seq);  

    // Generate complement
    for (int i = 0; seq[i] != '\0'; i++) {
        char base = toupper(seq[i]); 
        if (base == 'A') {
            seq[i] = 'T';
        } else if (base == 'T') {
            seq[i] = 'A';
        } else if (base == 'C') {
            seq[i] = 'G';
        } else if (base == 'G') {
            seq[i] = 'C';
        } else {
            printf("Invalid character '%c' in DNA sequence.\n", seq[i]);
            return 1; 
        }
    }

    printf("Complement: %s\n", seq);

    return 0;
}
