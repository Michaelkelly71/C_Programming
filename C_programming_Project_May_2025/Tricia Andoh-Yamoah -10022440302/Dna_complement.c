#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char sequence[1000];

    printf("Enter a DNA sequence: ");
    fgets(sequence, sizeof(sequence), stdin);
    sequence[strcspn(sequence, "\n")] = '\0';

    for (int i = 0; sequence[i] != '\0'; i++)
    {
        char c = sequence[i];
        if (c == 'A')
            sequence[i] = 'T';
        else if (c == 'T')
            sequence[i] = 'A';
        else if (c == 'C')
            sequence[i] = 'G';
        else if (c == 'G')
            sequence[i] = 'C';
        else if (c == 'a')
            sequence[i] = 't';
        else if (c == 't')
            sequence[i] = 'a';
        else if (c == 'c')
            sequence[i] = 'g';
        else if (c == 'g')
            sequence[i] = 'c';
        else
        {
            printf("Invalid DNA base: %c\n", c);
            return 1;
        }
    }

    printf("Complement: %s\n", sequence);
    return 0;
}