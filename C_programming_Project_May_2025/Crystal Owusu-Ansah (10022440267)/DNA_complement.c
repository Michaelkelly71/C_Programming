#include <stdio.h>
#include <string.h>

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);

    // Remove newline character if present
    size_t len = strlen(dna);
    if (dna[len - 1] == '\n') {
        dna[len - 1] = '\0';
    }

    printf("Complement: ");
    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A':
                printf("T");
                break;
            case 'T':
                printf("A");
                break;
            case 'C':
                printf("G");
                break;
            case 'G':
                printf("C");
                break;
            case 'a':
                printf("t");
                break;
            case 't':
                printf("a");
                break;
            case 'c':
                printf("g");
                break;
            case 'g':
                printf("c");
                break;
            default:
                printf("?"); // Unknown/invalid character
        }
    }

    printf("\n");
    return 0;
}
