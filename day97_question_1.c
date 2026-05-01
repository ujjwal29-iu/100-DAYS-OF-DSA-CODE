#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Structure for meeting interval
typedef struct {
    int start;
    int end;
} Meeting;

// Compare function for qsort (sort by start time)
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

// Min-Heap functions for end times
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0)
        return 0;

    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    // Add first meeting end time
    insertHeap(heap, &heapSize, meetings[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {
        // If room becomes free, remove earliest ending meeting
        if (meetings[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        // Add current meeting end time
        insertHeap(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];

    printf("Enter start and end time of each meeting:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    printf("Minimum number of rooms required: %d\n",
           minMeetingRooms(meetings, n));

    return 0;
}