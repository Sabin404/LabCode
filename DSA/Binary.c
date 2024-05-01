#include <stdio.h>
int binarySearch(int array[], int size, int target) {
 int low = 0;
 int high = size - 1;
 while (low <= high) {
 int mid = low + (high - low) / 2;
 if (array[mid] == target) {
 return mid;
 } else if (array[mid] < target) {
 low = mid + 1;
 } else {
 high = mid - 1;
 } }
 return -1; }
int main() {
 int target, index, size = 5;
 int array[5] = {10, 20, 30, 40, 50}; 
 printf("Array elements: ");
 for (int i = 0; i < size; i++) {
 printf("%d ", array[i]);
 }
 printf("\nEnter the value to search: ");
 scanf("%d", &target);
 index = binarySearch(array, size, target)
 if (index != -1) {
 printf("Target value %d found at index %d.\n", target, index+1); } else {
 printf("Target value %d not found in the array.\n", target); }
 return 0;}
