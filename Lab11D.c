#include <stdio.h>
#include <stdlib.h>

#define METERS_TO_FEET 3.28084
#define CONVERT(x) ((x) * METERS_TO_FEET)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <output_filename>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen("meters.txt", "r");
    FILE *output = fopen(argv[1], "w");

    if (!input || !output) {
        perror("Error opening file");
        return 1;
    }

    double meters;
    while (fscanf(input, "%lf", &meters) != EOF) {
        fprintf(output, "%.3f\n", CONVERT(meters));
    }

    fclose(input);
    fclose(output);
    return 0;
}
