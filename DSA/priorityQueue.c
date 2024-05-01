#include <stdio.h>
#define MAX_SIZE 100
// Structure to represent a priority queue element
struct PriorityQueueElement {
 int data;
 int priority;
};
// Structure to represent a priority queue
struct PriorityQueue {
 struct PriorityQueueElement elements[MAX_SIZE];
 int size;
};
// Function to initialize the priority queue
void initPriorityQueue(struct PriorityQueue *pq) {
 pq->size = 0;}
// Function to insert an element into the priority queue
void insert(struct PriorityQueue *pq, int data, int priority) {
 if (pq->size == MAX_SIZE) {
 printf("Priority Queue Overflow\n");
 return; }
 int i = pq->size - 1;
 while (i >= 0 && pq->elements[i].priority < priority) {
 pq->elements[i + 1] = pq->elements[i];
 i--; }
 pq->elements[i + 1].data = data;
 pq->elements[i + 1].priority = priority;
 pq->size++;}
// Function to delete the element with the highest priority from the priority queue
int deleteMax(struct PriorityQueue *pq) {
 if (pq->size == 0) {
 printf("Priority Queue Underflow\n");
 return -1; // return an error value
 }
 int maxData = pq->elements[0].data;
 for (int i = 1; i < pq->size; i++) {
 pq->elements[i - 1] = pq->elements[i];
 }
 pq->size--;
 return maxData;}
// Function to print the elements of the priority queue
void printPriorityQueue(struct PriorityQueue *pq) {
 printf("Priority Queue: ");
 for (int i = 0; i < pq->size; i++) {
 printf("(%d, %d) ", pq->elements[i].data, pq->elements[i].priority);
 }
 printf("\n");
}
// Main function to demonstrate priority queue operations
int main() {
 struct PriorityQueue pq;
 initPriorityQueue(&pq);
 insert(&pq, 10, 3);
 insert(&pq, 20, 2);
 insert(&pq, 30, 5);
 insert(&pq, 40, 1);
 printf("After Insertions:\n");
 printPriorityQueue(&pq);
 int maxElement = deleteMax(&pq);
 printf("Deleted Element with highest priority: %d\n", maxElement);
 printf("After Deletion:\n");
 printPriorityQueue(&pq);
 return 0;
}
