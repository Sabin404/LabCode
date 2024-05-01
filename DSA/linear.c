#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

// Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {12, 27, 34, 45, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    for (int i = 0; i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Linear Search
    int linearIndex = linearSearch(arr, n, target);
    if (linearIndex != -1) {
        printf("Linear Search: Element found at index %d\n", linearIndex);
    } else {
        printf("Linear Search: Element not found\n");
    }

    // Binary Search
    int binaryIndex = binarySearch(arr, 0, n - 1, target);
    if (binaryIndex != -1) {
        printf("Binary Search: Element found at index %d\n", binaryIndex);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}
