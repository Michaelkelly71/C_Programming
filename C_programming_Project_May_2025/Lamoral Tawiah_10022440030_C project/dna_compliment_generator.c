#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char dna[1000];

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i++)
    {
        char base = dna[i];

        switch (toupper(base))
        {
        case 'A':
            dna[i] = isupper(base) ? 'T' : 't';
            break;
        case 'T':
            dna[i] = isupper(base) ? 'A' : 'a';
            break;
        case 'C':
            dna[i] = isupper(base) ? 'G' : 'g';
            break;
        case 'G':
            dna[i] = isupper(base) ? 'C' : 'c';
            break;
        default:
            printf("Invalid DNA base detected: %c\n", base);
            return 1;
        }
    }

    printf("Complement: %s\n", dna);

    return 0;
}
