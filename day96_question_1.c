#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // left subarray start
    int j = mid + 1;   // right subarray start
    int k = left;      // temp array index
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // count inversions
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n", inversions);

    return 0;
}