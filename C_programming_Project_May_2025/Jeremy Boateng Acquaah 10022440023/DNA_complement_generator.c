#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char dna[1000];   // buffer for user input
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    int length = strlen(dna);

    // Traverse each character and print complement
    printf("Complement: ");
    for (int i = 0; i < length; i++) {
        char base = dna[i];

        // Handle both uppercase and lowercase
        switch (toupper(base)) {
            case 'A':
                putchar(isupper(base) ? 'T' : 't');
                break;
            case 'T':
                putchar(isupper(base) ? 'A' : 'a');
                break;
            case 'C':
                putchar(isupper(base) ? 'G' : 'g');
                break;
            case 'G':
                putchar(isupper(base) ? 'C' : 'c');
                break;
            default:
                printf("?");
        }
    }
    printf("\n");

    return 0;
}