#include <stdio.h>

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");
    if (!in || !out) {
        printf("Cannot open files.\n");
        return 1;
    }

    int ch, next;
    int in_single = 0, in_multi = 0;

    while ((ch = fgetc(in)) != EOF) {
        if (in_single) {
            if (ch == '\n') {
                in_single = 0;
                fputc(ch, out);
            }
        }
        else if (in_multi) {
            if (ch == '*') {
                next = fgetc(in);
                if (next == '/') in_multi = 0;
                else if (next != EOF) ungetc(next, in);
            }
        }
        else {
            if (ch == '/') {
                next = fgetc(in);
                if (next == '/') in_single = 1;
                else if (next == '*') in_multi = 1;
                else {
                    fputc(ch, out);
                    if (next != EOF) fputc(next, out);
                }
            }
            else {
                fputc(ch, out);
            }
        }
    }

    fclose(in);
    fclose(out);
    printf("Done! Comments removed.\n");
    return 0;
}
