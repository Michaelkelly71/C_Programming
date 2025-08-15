#include <stdio.h>

char make_upper(char ch) {
    return (ch >= 'a' && ch <= 'z') ? ch - 'a' + 'A' : ch;
}

char make_lower(char ch) {
    return (ch >= 'A' && ch <= 'Z') ? ch - 'A' + 'a' : ch;
}

int check_lower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int main() {
    char strand[100];
    int k = 0;

    printf("Input DNA sequence: ");
    scanf("%99s", strand);

    while (strand[k] != '\0') {
        char base = make_upper(strand[k]);

        if (base == 'A') strand[k] = 'T';
        else if (base == 'T') strand[k] = 'A';
        else if (base == 'C') strand[k] = 'G';
        else if (base == 'G') strand[k] = 'C';

        if (check_lower(strand[k])) {
            strand[k] = make_lower(strand[k]);
        }
        k++;
    }

    printf("Complement: %s\n", strand);
    return 0;
}