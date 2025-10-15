#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    size_t lines;
    size_t alnum_chars;
    size_t uppercase_letters;
    size_t words;
} Stats;

static void count_stats(FILE *fp, Stats *s) {
    s->lines = s->alnum_chars = s->uppercase_letters = s->words = 0;

    int ch;
    bool prev_is_delim = true;               
    bool saw_any_char = false;
    bool last_was_newline = false;

    while ((ch = fgetc(fp)) != EOF) {
        saw_any_char = true;

        // Count newlines for lines; we'll adjust at EOF
        if (ch == '\n') {
            s->lines++;
            last_was_newline = true;
        } else {
            last_was_newline = false;
        }

        // Count alphanumeric ASCII (A-Z a-z 0-9) using ctype's isalnum
        if (isalnum((unsigned char)ch)) {
            s->alnum_chars++;
        }

        // Count uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            s->uppercase_letters++;
        }

        // Word counting: tokens separated by ' ' or '\n' only
        bool is_delim = (ch == ' ' || ch == '\n');
        if (!is_delim && prev_is_delim) {
            s->words++;
        }
        prev_is_delim = is_delim;
    }

    //If file does not end with a newline and is not empty, add one line for EOF
    if (saw_any_char && !last_was_newline) {
        s->lines++;
    }
}

static int write_uppercase(FILE *fp_in, const char *out_name) {
    FILE *fp_out = fopen(out_name, "w");
    if (!fp_out) {
        perror("fopen UPPER");
        return 1;
    }
    int ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(toupper((unsigned char)ch), fp_out);
    }
    fclose(fp_out);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    Stats s;
    count_stats(fp, &s);

    // Reset to beginning for uppercase conversion
    if (fseek(fp, 0L, SEEK_SET) != 0) {
        perror("fseek");
        fclose(fp);
        return 1;
    }

    if (write_uppercase(fp, "UPPER") != 0) {
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // Output per the assignment
    printf("Lines: %zu\n", s.lines);
    printf("Alphanumeric characters (A-Z, a-z, 0-9): %zu\n", s.alnum_chars);
    printf("Uppercase letters (A-Z): %zu\n", s.uppercase_letters);
    printf("Words (separated by ' ' and '\\n'): %zu\n", s.words);

    return 0;
}
