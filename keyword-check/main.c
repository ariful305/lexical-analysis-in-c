#include <stdio.h>
#include <string.h>

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

int is_written(FILE *file, const char *word) {
    char temp[50];
    rewind(file);
    while (fscanf(file, "%s", temp) != EOF)
        if (strcmp(temp, word) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w+");

    if (!in || !out) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[50];
    fprintf(out, "// Unique keywords:\n");

    while (fscanf(in, "%s", word) != EOF)
        if (is_keyword(word) && !is_written(out, word))
            fprintf(out, "%s\n", word);

    fclose(in);
    fclose(out);
    printf("Done! Check output.c\n");
    return 0;
}
