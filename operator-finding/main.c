#include <stdio.h>

// Function to check if character is an operator
int is_operator(char ch) {
    char operators[] = "+-*/%=<>&|^!~?:";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) return 1;
    }
    return 0;
}

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        return 1;
    }

    char ch;
    fprintf(out, "Operators found: ");
    while ((ch = fgetc(in)) != EOF) {
        if (is_operator(ch)) {
            fprintf(out, "%c ", ch);
        }
    }

    fprintf(out, "\n//Done (operators).\n");

    fclose(in);
    fclose(out);

    printf("Operators written to output.c\n");
    return 0;
}
