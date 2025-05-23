#include <stdio.h>
#include <string.h>

// List of 32 C keywords
const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"
};

// Check if a word is a keyword
int is_keyword(const char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if the keyword was already written to output file
int is_already_written(FILE *out, const char *word) {
    char temp[50];
    rewind(out); // Go to start of file
    while (fscanf(out, "%s", temp) != EOF) {
        if (strcmp(temp, word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w+"); // open for read/write

    char word[50];

    if (!in || !out) {
        printf("Error opening files.\n");
        return 1;
    }

    fprintf(out, "// Unique keywords found:\n");

    while (fscanf(in, "%s", word) != EOF) {
        if (is_keyword(word) && !is_already_written(out, word)) {
            fprintf(out, "%s\n", word);
        }
    }

    printf("Done! Check output.c\n");

    fclose(in);
    fclose(out);
    return 0;
}
