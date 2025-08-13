#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_key(int key) {
    return key >= 0;
}

char encrypt_char(char ch, int key) {
    if (!isalpha(ch)) {
        return ch; 
    }
    char base = isupper(ch) ? 'A' : 'a';
    int pos = ch - base; 
    pos = (pos + key) % 26; 
    return (char)(base + pos); 
}

void encrypt_text(const char *plaintext, char *ciphertext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt_char(plaintext[i], key);
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void write_ciphertext_to_file(const char *ciphertext) {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        return;
    }
    fprintf(fp, "ciphertext: %s\n", ciphertext);
    fclose(fp);
}

int main() {
    char source[20];
    char plainText[1000];
    char cipherText[1000];
    int key;

    printf("Enter 'console' to input plaintext or 'file' to read from input.txt: ");
    scanf("%s", source);
    getchar(); 

    do {
        printf("Enter key (non-negative integer): ");
        if (scanf("%d", &key) != 1 || !is_valid_key(key)) {
            printf("Error: Key must be a non-negative integer\n");
            while (getchar() != '\n'); 
            continue;
        }
        break;
    } while (1);
    getchar(); 
    key = key % 26; 

    if (strcmp(source, "file") == 0) {
        FILE *fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("Error: Cannot open input.txt\n");
            return 1;
        }
        if (!fgets(plainText, sizeof(plainText), fp)) {
            printf("Error: Empty or invalid file\n");
            fclose(fp);
            return 1;
        }
        fclose(fp);
    } else {
        printf("plaintext: ");
        fgets(plainText, sizeof(plainText), stdin);
    }

    size_t len = strlen(plainText);
    if (len > 0 && plainText[len - 1] == '\n') {
        plainText[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Error: Empty input\n");
        return 1;
    }

    encrypt_text(plainText, cipherText, key);
    printf("ciphertext: %s\n", cipherText);
    write_ciphertext_to_file(cipherText);

    return 0;
}