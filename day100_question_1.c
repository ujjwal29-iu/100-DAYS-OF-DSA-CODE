#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
    int count;
} Element;

void merge(Element arr[], int left, int mid, int right, int result[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Element L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].value > R[j].value) {
            // Right element is smaller
            rightCount++;
            arr[k++] = R[j++];
        } else {
            // Count smaller elements on right
            result[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
    }

    while (i < n1) {
        result[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(Element arr[], int left, int right, int result[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, result);
        mergeSort(arr, mid + 1, right, result);

        merge(arr, left, mid, right, result);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int input[n];
    Element arr[n];
    int result[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);

        arr[i].value = input[i];
        arr[i].index = i;
        result[i] = 0;
    }

    mergeSort(arr, 0, n - 1, result);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}