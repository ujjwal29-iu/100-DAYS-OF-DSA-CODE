#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is larger than maxTime, impossible
        if (boards[i] > maxTime)
            return 0;

        if (currentSum + boards[i] <= maxTime) {
            currentSum += boards[i];
        } else {
            painters++;
            currentSum = boards[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

int findMinTime(int boards[], int n, int k) {
    int low = 0, high = 0, mid, answer;

    // low = max board length, high = sum of all boards
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            answer = mid;
            high = mid - 1; // try smaller answer
        } else {
            low = mid + 1; // increase time
        }
    }

    return answer;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", findMinTime(boards, n, k));

    return 0;
}