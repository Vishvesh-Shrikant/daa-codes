#include <stdio.h>

int max, min;
int a[100];

void maxmin(int i, int j) {
    int max1, min1, mid;
    if (i == j) {
        max = min = a[i];
    } else {
        if (i == j - 1) {
            if (a[i] < a[j]) {
                max = a[j];
                min = a[i];
            } else {
                max = a[i];
                min = a[j];
            }
        } else {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

int main() {
    int i, n;
    printf("\nEnter size of array : ");
    scanf("%d", &n);
    printf("Enter the numbers : \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    max = a[0]; // It's generally better to initialize max and min with the first element of the relevant part of the array
    min = a[0]; // considering the function call starts from index 1.
    maxmin(1, n);
    printf("Minimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}
