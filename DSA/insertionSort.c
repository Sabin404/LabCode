#include <stdio.h>
void insertionSort(int arr[], int n) {
 int i, j, key;
 for (i = 1; i < n; i++) {
 key = arr[i];
 j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j = j - 1;
 }
 arr[j + 1] = key;
 }}
int main() {
 int n, i;
 int arr[n];
 printf("Enter the size of the array: ");
 scanf("%d", &n);
 if (n <= 0) {
 printf("Invalid array size. Exiting...\n");
 return 0;
 }
 printf("Enter the elements of the array:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 insertionSort(arr, n);
 printf("The sorted array is:\n");
 for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 return 0;
}
