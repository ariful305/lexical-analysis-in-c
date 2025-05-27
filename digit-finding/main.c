#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        return 1;
    }

    int digit_count[10] = {0}; // index 0–9 for digits 0–9
    char ch;

    while ((ch = fgetc(in)) != EOF) {
        if (isdigit(ch)) {
            digit_count[ch - '0']++;
        }
    }

    // Write the results to output.c
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            fprintf(out, "%d = %d\n", i, digit_count[i]);
        }
    }

    fclose(in);
    fclose(out);

    printf("Digit frequencies written to output.c\n");
    return 0;
}
