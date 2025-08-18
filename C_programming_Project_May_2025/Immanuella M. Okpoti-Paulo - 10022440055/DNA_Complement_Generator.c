#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char dna[100];

    printf("Enter a DNA sequence: ");
    scanf("%s", dna); 

    for (int i = 0; dna[i] != '\0'; i++)
    {
        char base = toupper(dna[i]);

        switch (base)
        {
            case 'A':
                dna[i] = islower(dna[i]) ? 't' : 'T';
                break;
            case 'T':
                dna[i] = islower(dna[i]) ? 'a' : 'A';
                break;
            case 'C':
                dna[i] = islower(dna[i]) ? 'g' : 'G';
                break;
            case 'G':
                dna[i] = islower(dna[i]) ? 'c' : 'C';
                break;
            default:
                // If invalid character, replace with '?' (optional)
                dna[i] = '?';
        }
    }

    printf("Complement: %s\n", dna);

    return 0;
}
