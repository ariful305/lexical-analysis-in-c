#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of 32 C keywords
const char *keywords[] = {
  "auto", "break", "case", "char", "const", "continue", "default", "do",
  "double", "else", "enum", "extern", "float", "for", "goto", "if",
  "int", "long", "register", "return", "short", "signed", "sizeof", "static",
  "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Function to check if a word is a keyword
int is_keyword(const char *word) {
  for (int i = 0; i < 32; i++) {
    if (strcmp(word, keywords[i]) == 0)
      return 1;
  }
  return 0;
}

int main() {
  FILE *input = fopen("input.c", "r");
  FILE *output = fopen("output.c", "w");

  if (!input || !output) {
    printf("Error opening files.\n");
    return 1;
  }

  char ch;
  char word[100];
  int index = 0;

  while ((ch = fgetc(input)) != EOF) {
    if (ch == '#') {
      // Copy whole preprocessor line as-is
      fputc(ch, output);
      while ((ch = fgetc(input)) != EOF && ch != '\n') {
        fputc(ch, output);
      }
      if (ch == '\n') {
        fputc(ch, output);
      }
    }
    else if (isalpha(ch) || ch == '_') {
      // Read a word (identifier or keyword)
      word[index++] = ch;

      while (1) {
        ch = fgetc(input);
        if (isalnum(ch) || ch == '_') {
          word[index++] = ch;
        } else {
          break;
        }
      }
      word[index] = '\0';  // end the string
      index = 0;

      if (is_keyword(word)) {
        // If keyword, print whole word
        fprintf(output, "%s", word);
      } else {
        // If not keyword, truncate to 5 chars max
        if (strlen(word) > 5) {
          word[5] = '\0';
        }
        fprintf(output, "%s", word);
      }

      // Print the character that ended the word (non-alnum)
      if (ch != EOF) {
        fputc(ch, output);
      }
    }
    else {
      // For all other characters, just copy as-is
      fputc(ch, output);
    }
  }

  fclose(input);
  fclose(output);

  printf("Done! Check output.c\n");
  return 0;
}
