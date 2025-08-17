#include <stdio.h>
#include <string.h>
int main(void)
{
    char dna[1000];

    // Ask user for DNA sequence
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);  // read string input (no spaces)

    int length = strlen(dna);

    // Process each character
    for (int i = 0; i < length; i++)
    {
        switch (dna[i])
        {
            // Handle uppercase bases
            case 'A': dna[i] = 'T'; break;
            case 'T': dna[i] = 'A'; break;
            case 'C': dna[i] = 'G'; break;
            case 'G': dna[i] = 'C'; break;

            // Handle lowercase bases (bonus)
            case 'a': dna[i] = 't'; break;
            case 't': dna[i] = 'a'; break;
            case 'c': dna[i] = 'g'; break;
            case 'g': dna[i] = 'c'; break;

            // Handle invalid characters
            default: 
                printf("\nInvalid base '%c' detected! Only A, T, C, G allowed.\n", dna[i]);
                return 1;
        }
    }

    // Print result
    printf("Complement: %s\n", dna);

    return 0;
}
