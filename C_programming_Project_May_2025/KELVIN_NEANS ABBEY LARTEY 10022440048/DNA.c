#include <stdio.h>
#include <string.h>

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    char dna[100];
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);
    
    for (int i = 0; dna[i] != '\0'; i++) {
        char c = to_upper(dna[i]);
        if (c == 'A') dna[i] = 'T';
        else if (c == 'T') dna[i] = 'A';
        else if (c == 'C') dna[i] = 'G';
        else if (c == 'G') dna[i] = 'C';
        
        
        if (is_lower(dna[i])) {
            dna[i] = to_lower(dna[i]);
        }
    }
    
    printf("Complement: %s\n", dna);
    return 0;
}