#include <stdio.h>
#include <ctype.h>

int main() {
    char originalDNA[500];

    printf("Enter DNA sequence: ");
    scanf("%s", originalDNA);

    for (int x = 0; originalDNA[x] != '\0'; x++) {
        char base = toupper(originalDNA[x]);

        if (base == 'A') originalDNA[x] = 'T';
        else if (base == 'T') originalDNA[x] = 'A';
        else if (base == 'C') originalDNA[x] = 'G';
        else if (base == 'G') originalDNA[x] = 'C';
    }

    printf("Complement: %s\n", originalDNA);
    return 0;
}
