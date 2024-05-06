#include <stdio.h>

void selectionSort(int A[], int n) {
    int i, j, posmin, tmp;
    for (i = 0; i < n - 1; i++) {
        posmin = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[posmin]) {
                posmin = j;
            }
        }
        tmp = A[i];
        A[i] = A[posmin];
        A[posmin] = tmp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    int i;

    printf("Array original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Array ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}