
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void count_text(const char *text, int *l, int *w, int *s) {
    int in_word=0; *l=*w=*s=0;

    for(int i=0; text[i]; i++) {
        if(isalpha(text[i])) (*l)++;
        if(isspace(text[i])) { if(in_word) (*w)++; in_word=0; } else in_word=1;
        switch(text[i]) { case '.': case '!': case '?': (*s)++; break; }
    }
    if(in_word) (*w)++;
    if(*w>0 && *s==0) *s=1;
}
int main() {

    char text[1024], source[20], out[20];
    printf("Enter 'console' or 'file': "); scanf("%s", source); getchar();

    if(!strcmp(source, "file")) {
        FILE *fp=fopen("input.txt", "r");
        if(!fp || !fgets(text, 1024, fp)) { printf("Error: Cannot read input.txt\n"); if(fp) fclose(fp); return 1; }
        fclose(fp);
    }
    else { printf("Text: "); fgets(text, 1024, stdin); }

    size_t len=strlen(text);

    if(len && text[len-1]=='\n') text[--len]='\0';

    if(!len) { printf("Error: Empty input\n"); return 1; }

    int l, w, s; count_text(text, &l, &w, &s);
    int grade=w?round(0.0588*(100.0*l)/w-0.296*(100.0*s)/w-15.8):0;
    sprintf(out, grade<1?"Before Grade 1\n":grade>=16?"Grade 16+\n":"Grade %d\n", grade);
    printf("%s", out);
    FILE *fp=fopen("output.txt", "w");
    if(!fp) { printf("Error opening output file!\n"); return 0; }
    fprintf(fp, "%s", out); fclose(fp);
    return 0;
}
