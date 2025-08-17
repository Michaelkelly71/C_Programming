#include <stdio.h>
#include <ctype.h>

char get_base(char base){
    
    base = toupper(base);

    if (base == 'A'){
        return 'T';
    }else if (base == 'T'){
        return 'A';
    }else if (base == 'G'){
        return 'C';
    }else if (base == 'C'){
        return 'G';
    }else{
        return '?';
    }
}

int main(){
    char sequence[256];
    printf("Enter your DNA Sequence: ");
    scanf("%s", sequence);

    char dna_complement[256];
    int invalid = 0;

    int i = 0; 
    while(sequence[i] != '\0'){
       char result = get_base(sequence[i]);

    //check if result has invalid character
       if (result == '?'){
        invalid = 1;
        dna_complement[i] = '?';
       }else{
        dna_complement[i] = result;
       }

       i++;
    }

    dna_complement[i] = '\0';

    if (invalid){
        printf("Error: Sequence has invalid characters.\n");
        printf("Complement: %s\n", dna_complement);
    }else{
        printf("Complement: %s\n", dna_complement);
    }

    return 0;
}