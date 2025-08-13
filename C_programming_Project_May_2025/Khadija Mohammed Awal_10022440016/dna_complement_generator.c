#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_dna(const char *sequence) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        char base = toupper(sequence[i]);
        if (base != 'A' && base != 'T' && base != 'C' && base != 'G') {
            return 0; 
        }
    }
    return 1;
}

void generate_complement(const char *sequence, char *complement) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        char base = toupper(sequence[i]);
        switch (base) {
            case 'A':
                complement[i] = islower(sequence[i]) ? 't' : 'T';
                break;
            case 'T':
                complement[i] = islower(sequence[i]) ? 'a' : 'A';
                break;
            case 'C':
                complement[i] = islower(sequence[i]) ? 'g' : 'G';
                break;
            case 'G':
                complement[i] = islower(sequence[i]) ? 'c' : 'C';
                break;
            default:
                complement[i] = sequence[i]; 
                break;
        }
    }
    complement[strlen(sequence)] = '\0';
}

void write_complement_to_file(const char *complement) {
    FILE *fp = fopen("dna_output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        return;
    }
    fprintf(fp, "Complement: %s\n", complement);
    fclose(fp);
}

int main() {

    char sequence[1024];
    char complement[1024];
    char source[20];
    printf("Enter 'console' to input DNA sequence or 'file' to read from dna_input.txt: ");
    scanf("%s", source);
    getchar(); 

    if (strcmp(source, "file") == 0) {
        FILE *fp = fopen("dna_input.txt", "r");
        if (fp == NULL) {
            printf("Error: Cannot open dna_input.txt\n");
            return 1;
        }
        if (!fgets(sequence, sizeof(sequence), fp)) {
            printf("Error: Empty or invalid file\n");
            fclose(fp);
            return 1;
        }
        fclose(fp);
    } else {
        printf("Enter a DNA sequence: ");
        fgets(sequence, sizeof(sequence), stdin);
    }

    size_t len = strlen(sequence);
    if (len > 0 && sequence[len - 1] == '\n') {
        sequence[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Error: Empty input\n");
        return 1;
    }
    if (!is_valid_dna(sequence)) {
        printf("Error: Invalid DNA sequence (use A, T, C, G only)\n");
        return 1;
    }

    generate_complement(sequence, complement);
    printf("Complement: %s\n", complement);
    write_complement_to_file(complement);

    return 0;
}