#include <stdio.h>

int main() {
    char dna[1000];
    int i = 0;
    
    printf("Enter a DNA sequence: ");
    gets(dna);
    
    printf("Complement: ");
    
    while(dna[i] != '\0') {
        if(dna[i] == 'A') {
            printf("T");
        }
        else if(dna[i] == 'T') {
            printf("A");
        }
        else if(dna[i] == 'C') {
            printf("G");
        }
        else if(dna[i] == 'G') {
            printf("C");
        }
        else if(dna[i] == 'a') {
            printf("t");
        }
        else if(dna[i] == 't') {
            printf("a");
        }
        else if(dna[i] == 'c') {
            printf("g");
        }
        else if(dna[i] == 'g') {
            printf("c");
        }
        else {
            printf("%c", dna[i]);
        }
        i++;
    }
    
    return 0;
}