#include <stdio.h>

void leakyBucket(int s, int r, int n, int input[]) {
    int c = 0;

    printf("\nTime\tIn\tOut\tContent\tDrop\n");

    for (int t = 0; t < n; t++) {
        c += input[t];
        int d = (c > s) ? c - s : 0;
        c = (c > s) ? s : c;

        int sent = (c > r) ? r : c;
        c -= sent;

        printf("%d\t%d\t%d\t%d\t%d\n", t + 1, input[t], sent, c, d);
    }

    while (c > 0) {
        int sent = (c > r) ? r : c;
        c -= sent;
        printf("%d\t0\t%d\t%d\t0\n", ++n, sent, c);
    }
}

int main() {
    int s, r, n;

    printf("Enter bucket size, rate, and number of time units: ");
    scanf("%d %d %d", &s, &r, &n);

    int input[n];
    printf("Enter packets for each time unit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    leakyBucket(s, r, n, input);

    return 0;
}
