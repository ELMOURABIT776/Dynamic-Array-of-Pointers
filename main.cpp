#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_arrays, size, sum;


    printf("Enter number of arrays: ");
    scanf("%d", &num_arrays);


    int **arrays = (int**)malloc(num_arrays * sizeof(int*));
    if (arrays == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (int i = 0; i < num_arrays; i++) {
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &size);


        arrays[i] = (int*)malloc(size * sizeof(int));
        if (arrays[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter elements for array %d: ", i + 1);
        for (int j = 0; j < size; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }


    for (int i = 0; i < num_arrays; i++) {
        sum = 0;
        printf("Array %d: ", i + 1);
        for (int j = 0; j < size; j++) {
            printf("%d ", arrays[i][j]);
            sum += arrays[i][j];
        }
        printf("\nSum of Array %d: %d\n", i + 1, sum);


        free(arrays[i]);
    }


    free(arrays);

    return 0;
}
