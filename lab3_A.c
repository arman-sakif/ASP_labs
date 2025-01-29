#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // user input
    puts("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = malloc(n * sizeof(int));

    // check for error
    if (arr == NULL) {
        puts("Memory allocation failed.");
    }

    // user input of arr elems
    puts("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    // Print in reverse
    printf("Elements in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}
