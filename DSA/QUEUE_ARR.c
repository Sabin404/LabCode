#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
 if (rear == SIZE - 1) {
 printf("Queue is full. Cannot enqueue.\n");
 return; }
 if (front == -1)
 front = 0;
 rear++;
 queue[rear] = value;}
int dequeue() {
 int value;
 if (front == -1 || front > rear) {
 printf("Queue is empty. Cannot dequeue.\n");
 return -1; }
 value = queue[front];
 front++;
 return value;}
int isEmpty() {
 if (front == -1 || front > rear)
 return 1;
 else
 return 0;}
int isFull() {
 if (rear == SIZE - 1)
 return 1;
 else
 return 0;}
void display() {
 if (isEmpty()) {
 printf("Queue is empty.\n");
 return; }
 printf("Queue elements: ");
 for (int i = front; i <= rear; i++)
 printf("%d ", queue[i]);
 printf("\n");}
int main() {
 enqueue(1);
 enqueue(2);
 enqueue(3);
 display();
 printf("Dequeued element: %d\n", dequeue());
 display();
 printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No");
 printf("Is queue full? %s\n", isFull() ? "Yes" : "No");
 return 0;}
