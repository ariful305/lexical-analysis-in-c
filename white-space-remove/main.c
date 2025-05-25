#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
      return 1; // it's a keyword
  }
  return 0; // not a keyword
}

int main() {
  FILE *in = fopen("input.c", "r");
  FILE *out = fopen("output.c", "w");
  char ch, word[100];
  int i = 0;

  if (!in || !out) {
    printf("Error opening file.\n");
    return 1;
  }

  while ((ch = fgetc(in)) != EOF) {
    // Keep #include line unchanged
    if (ch == '#') {
      fputc(ch, out);
      while ((ch = fgetc(in)) != EOF && ch != '\n') {
        fputc(ch, out);
      }
      fputc('\n', out);
      continue;
    }

    // If it's the start of a word (letter or _)
    if (isalpha(ch) || ch == '_') {
      word[i++] = ch;
      while ((ch = fgetc(in)) != EOF && (isalnum(ch) || ch == '_')) {
        word[i++] = ch;
      }
      word[i] = '\0';  // End the word
      i = 0;

      // Truncate word if not a keyword
      if (!is_keyword(word)) {
        word[5] = '\0';  // keep only first 5 letters
      }

      fprintf(out, "%s", word);

      // If next char is not space, add it
      if (!isspace(ch)) {
        fputc(ch, out);
      }
    } else {
      // Skip any space, tab, newline
      if (!isspace(ch)) {
        fputc(ch, out);
      }
    }
  }

  fclose(in);
  fclose(out);

  printf("Done! See output.c\n");
  return 0;
}
