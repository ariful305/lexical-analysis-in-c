#include <stdio.h>

int main() {
    FILE *in = fopen("input.c", "r");
    FILE *out = fopen("output.c", "w");

    if (!in || !out) {
        printf("Cannot open files.\n");
        return 1;
    }

    int c, next;
    int singleComment = 0;
    int multiComment = 0;

    while ((c = fgetc(in)) != EOF) {
        if (singleComment) {
            if (c == '\n') {
                singleComment = 0;
                fputc(c, out);
            }
        } else if (multiComment) {
            if (c == '*') {
                next = fgetc(in);
                if (next == '/') {
                    multiComment = 0;
                } else if (next != EOF) {
                    ungetc(next, in);
                }
            }
        } else {
            if (c == '/') {
                next = fgetc(in);
                if (next == '/') {
                    singleComment = 1;
                } else if (next == '*') {
                    multiComment = 1;
                } else {
                    if (next != EOF) {
                        fputc(c, out);
                        fputc(next, out);
                    } else {
                        fputc(c, out);
                    }
                }
            } else {
                fputc(c, out);
            }
        }
    }

    fclose(in);
    fclose(out);

    printf("Done! Comments removed.\n");
    return 0;
}
