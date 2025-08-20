#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char dna_sequence[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna_sequence, sizeof(dna_sequence), stdin);

    dna_sequence[strcspn(dna_sequence, "\n")] = 0;

    printf("Complement: ");
    for (int i = 0, n = strlen(dna_sequence); i < n; i++)
    {
        char base = toupper(dna_sequence[i]);
        if (base == 'A')
        {
            printf("T");
        }
        else if (base == 'T')
        {
            printf("A");
        }
        else if (base == 'C')
        {
            printf("G");
        }
        else if (base == 'G')
        {
            printf("C");
        }
        else
        {
            printf("%c", dna_sequence[i]);
        }
    }
    printf("\n");

    return 0;
}