#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char dna[1000];   // buffer for input sequence
    printf("Enter a DNA sequence: ");
    scanf("%s", dna); // read input (no spaces)

    int length = strlen(dna);

    // Loop through each character and print complement
    printf("Complement: ");
    for (int i = 0; i < length; i++)
    {
        char base = dna[i];
        char comp;

        // Handle uppercase and lowercase
        switch (toupper(base))
        {
            case 'A':
                comp = (isupper(base)) ? 'T' : 't';
                break;
            case 'T':
                comp = (isupper(base)) ? 'A' : 'a';
                break;
            case 'C':
                comp = (isupper(base)) ? 'G' : 'g';
                break;
            case 'G':
                comp = (isupper(base)) ? 'C' : 'c';
                break;
            default:
                comp = base; // if not ATCG, leave unchanged
        }

        printf("%c", comp);
    }

    printf("\n");
    return 0;
}
