#include<stdio.h>
#include<stdbool.h>
#define max 10 
int stack[max];
int tos = -1;
bool isEmpty() {
 return (tos == -1);
}
bool isFull() {
 return (tos == max - 1);
}
void push(int data) {
 if (tos == max - 1) {
 printf("Stack Overflow");
 } else {
 tos++;
 stack[tos] = data;
 }}
int pop() {
 if (tos == -1) {
 printf("Stack UnderFlow");
 } else {
 int popValue = stack[tos];
 tos--;
 return popValue;
 }
}
void display() {
 if (tos == -1) {
 printf("Stack has no value");
 } else {
 for (int i = tos; i >=0; i--) {
 printf("Data[%d] : %d\t",i ,stack[i]);
 }
 }
}
int main() {
 push(2);
 push(3);
 push(4);
 push(5);
 push(6);
 int data = pop();
 printf("Pop value %d \n\n", data);
 display();
 return 0;}
