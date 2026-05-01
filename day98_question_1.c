#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for qsort (sort by start time)
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n == 0)
        return;

    // Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    // First interval goes directly
    result[index] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping, merge
        if (arr[i].start <= result[index].end) {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap, move to next interval
            index++;
            result[index] = arr[i];
        }
    }

    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter start and end of each interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}