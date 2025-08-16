// dna_complement.c
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static char complement_base(char b)
{
     if (b == 'A')
          return 'T';
     if (b == 'T')
          return 'A';
     if (b == 'C')
          return 'G';
     if (b == 'G')
          return 'C';
     if (b == 'a')
          return 't';
     if (b == 't')
          return 'a';
     if (b == 'c')
          return 'g';
     if (b == 'g')
          return 'c';
     return b; // leave any other char unchanged
}

int main(void)
{
     char seq[10000];

     printf("Enter a DNA sequence: ");
     if (!fgets(seq, sizeof(seq), stdin))
          return 1;

     // strip trailing newline if present
     size_t n = strlen(seq);
     if (n && seq[n - 1] == '\n')
          seq[--n] = '\0';

     for (size_t i = 0; i < n; i++)
     {
          seq[i] = complement_base(seq[i]);
     }

     printf("Complement: %s\n", seq);
     return 0;
}
