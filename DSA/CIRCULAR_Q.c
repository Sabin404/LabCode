#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
 if ((rear + 1) % SIZE == front) {
 printf("Queue is full\n");
 } else {
 if (front == -1)
 front = 0;
 rear = (rear + 1) % SIZE;
 queue[rear] = value;
 printf("%d enqueued to queue\n", value);
 }}
void dequeue() {
 if (front == -1) {
 printf("Queue is empty\n");
 } else {
 printf("%d dequeued from queue\n", queue[front]);
 if (front == rear) {
 front = -1;
 rear = -1;
 } else {
 front = (front + 1) % SIZE; }
void display() {
 if (front == -1)
 printf("Queue is empty\n");
 else {
 int i = front;
 printf("Queue elements: ");
 do {
 printf("%d ", queue[i]);
 i = (i + 1) % SIZE;
 } while (i != (rear + 1) % SIZE);
 printf("\n");}}
int main() {
 enqueue(1);
 enqueue(2);
 enqueue(3);
 enqueue(4);
 enqueue(5);
 enqueue(6); // Trying to enqueue when queue is full
 display();
 dequeue();
 dequeue();
 display();
 enqueue(7);
 display();
 return 0;
}
