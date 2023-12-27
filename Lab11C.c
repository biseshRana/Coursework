#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100];
    char c;
    int chars = 0, words = 0, lines = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    while ((c = getc(fp)) != EOF) {
        if (!isspace(c)) chars++;
        if (c == '\n') lines++;
        if (isspace(c) || c == '\n') words++;
    }

    printf("Characters: %d, Words: %d, Lines: %d\n", chars, words, lines);

    fclose(fp);
    return 0;
}
