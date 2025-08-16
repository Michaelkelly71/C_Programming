// caesar.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     long key;
     char buf[64];

     printf("key: ");
     if (!fgets(buf, sizeof(buf), stdin))
          return 1;
     char *endptr = NULL;
     key = strtol(buf, &endptr, 10);
     if (endptr == buf || key < 0)
     {
          fprintf(stderr, "Invalid key. Use a nonnegative integer.\n");
          return 1;
     }
     key %= 26; // normalize

     char text[10000];
     printf("plaintext: ");
     if (!fgets(text, sizeof(text), stdin))
          return 1;

     // Encrypt in place and print
     printf("ciphertext: ");
     for (size_t i = 0; text[i] != '\0'; i++)
     {
          unsigned char c = (unsigned char)text[i];
          if (isupper(c))
          {
               char enc = (char)('A' + ((c - 'A') + key) % 26);
               putchar(enc);
          }
          else if (islower(c))
          {
               char enc = (char)('a' + ((c - 'a') + key) % 26);
               putchar(enc);
          }
          else
          {
               putchar(c);
          }
     }
     // fgets keeps newline; already printed
     return 0;
}
