#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char dna[100]; 
    printf("Enter a DNA sequence: ");
    scanf("%99s", dna); 

    int length = strlen(dna);

    for (int i = 0; i < length; i++)
    {
        char base = toupper(dna[i]); 

        switch (base)
        {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
            default:
                printf("Error: Invalid base '%c'\n", dna[i]);
                return 1;
        }
    }

    printf("Complement: %s\n", dna);
    return 0;
}
