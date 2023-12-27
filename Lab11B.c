#include <stdio.h>
#include <stdlib.h>

int main() {
    double* numbers = (double*)malloc(sizeof(double));
    int count = 0;
    char choice;
    double sum = 0;

    do {
        printf("Enter a number: ");
        scanf("%lf", &numbers[count]);
        sum += numbers[count];
        count++;

        numbers = (double*)realloc(numbers, (count + 1) * sizeof(double));

        printf("List of numbers:\n");
        for (int i = 0; i < count; ++i) {
            printf("%.6f\n", numbers[i]);
        }
        printf("Updated average is: %.6f\n", sum / count);

        printf("More numbers (Y/N)? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    free(numbers);
    return 0;
}
