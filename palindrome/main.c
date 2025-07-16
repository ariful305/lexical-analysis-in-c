#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char word[100], rev[100];

    fp = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");
    if (fp == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(rev, word);
        strrev(rev); 
        if (strcmp(word, rev) == 0) {
            fprintf(out,"Palindrome: %s\n", word);          
        } else {
            fprintf(out,"Not Palindrome: %s\n", word);
        }
    }

    fclose(fp);
    return 0;
}
