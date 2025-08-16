#include <stdio.h>
#include <string.h>

int main() {
    char DNA [250];
    printf("Enter your DNA sequence: \n");
    scanf("%s", &DNA);

    for (int i = 0; i < strlen(DNA); i++) {
        if (DNA[i] == 'A' || DNA[i] == 'a') {
            DNA[i] = (DNA[i] == 'A') ?'T': 't';
        } 
        else if (DNA[i] == 'T' || DNA[i] == 't'){
            DNA[i] = (DNA[i] =='A') ? 'A' : 'a';
        }
        else if (DNA[i] == 'C' || DNA[i] == 'c') {
            DNA[i] = (DNA[i] == 'G') ?'G' : 'g';
        }
        else if (DNA[i] == 'G' || DNA[i] == 'g') {
            DNA[i] = (DNA[i] == 'C') ?'C' :'c';
        }
        else {
            printf("Invalid Sequence:%s\n", DNA[i]);
            return 1;
        }
    }
    printf("Complement: %s\n", DNA);
    return 0;   

}


