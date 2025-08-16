// readability.c
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
     char text[10000];

     printf("Text: ");
     if (!fgets(text, sizeof(text), stdin))
          return 1;

     long letters = 0, words = 0, sentences = 0;
     bool in_word = false;

     for (size_t i = 0; text[i] != '\0'; i++)
     {
          unsigned char ch = (unsigned char)text[i];

          if (isalpha(ch))
          {
               letters++;
          }
          if (ch == '.' || ch == '!' || ch == '?')
          {
               sentences++;
          }

          if (!isspace(ch) && !in_word)
          {
               in_word = true;
               words++;
          }
          else if (isspace(ch))
          {
               in_word = false;
          }
     }

     if (words == 0)
     { // avoid divide-by-zero
          puts("Before Grade 1");
          return 0;
     }

     double L = (letters * 100.0) / words;
     double S = (sentences * 100.0) / words;
     double index = 0.0588 * L - 0.296 * S - 15.8;
     int grade = (int)lround(index);

     if (grade < 1)
     {
          puts("Before Grade 1");
     }
     else if (grade >= 16)
     {
          puts("Grade 16+");
     }
     else
     {
          printf("Grade %d\n", grade);
     }
     return 0;
}
