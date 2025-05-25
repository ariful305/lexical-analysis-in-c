#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"
};

int is_keyword(const char *word) {
    for (int i = 0; i < 32; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");
    if (!in || !out) {
        printf("Error opening files.\n");
        return 1;
    }

    char ch, word[100];
    int i = 0;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == '#') {
            fputc(ch, out);
            while ((ch = fgetc(in)) != EOF && ch != '\n')
                fputc(ch, out);
            fputc('\n', out);
        }
        else if (isalpha(ch) || ch == '_') {
            word[i++] = ch;
            while ((ch = fgetc(in)) != EOF && (isalnum(ch) || ch == '_'))
                word[i++] = ch;
            word[i] = '\0';
            i = 0;

            if (!is_keyword(word) && strlen(word) > 5)
                word[5] = '\0';
            fprintf(out, "%s", word);
            if (ch != EOF) fputc(ch, out);
        }
        else {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Done! Check output.c\n");
    return 0;
}
