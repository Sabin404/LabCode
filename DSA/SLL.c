#include <stdio.h>
#include <stdlib.h>
struct Node{ // structure 
 int data;
 struct Node *next;
};
struct Node *head = NULL;
void insertAtBeginning(int value){ //insert at begining
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));//size allocation for a node.
if(head==NULL){
head=newnode;}else{
 newNode->data = value;
 newNode->next = head;
 head = newNode;}}
//Insertion 
void insertAtEnd(int value){ //insert at end 
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->next = NULL;
 if (head == NULL) {
 head = newNode;
 return; }
 struct Node *temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;}
void insertFromSpecificPosition(int value, int position){ //insert at specific position 
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode->data = value;
 if (position == 1){
 newNode->next = head;
 head = newNode;
 return; }
 struct Node *temp = head;
 for (int i = 1; i < position - 1 && temp != NULL; i++){
 temp = temp->next;
 }
 if (temp == NULL){
 printf("Invalid position. Insertion failed.\n");
 free(newNode);
 }
 newNode->next = temp->next;
 temp->next = newNode;}
//Deletion 
void deleteFromBeginning(){
 if (head == NULL){
 printf("Linked list is empty. Nothing to delete.\n");
 }
 struct Node *temp = head;
 head = head->next;
 free(temp);}
void deleteFromEnd(){//Delete from end
 if (head == NULL){
 printf("Linked list is empty. Nothing to delete.\n");
 return;
 } if (head->next == NULL){
 free(head);
 head = NULL;
}
 struct Node *temp = head;
 while (temp->next->next != NULL){
 temp = temp->next; }
 free(temp->next);
 temp->next = NULL;
}
void deleteFromSpecificPosition(int position){
 if (head == NULL){
 printf("Linked list is empty. Nothing to delete.\n");
 }
 if (position == 1){
 struct Node *temp = head;
 head = head->next;
 free(temp); }
 struct Node *temp = head;
 struct Node *prev = NULL;
 for (int i = 1; i < position && temp != NULL; i++){
 prev = temp;
 temp = temp->next; }
 if (temp == NULL){
 printf("Invalid position. Deletion failed.\n");
 return; }
 prev->next = temp->next;
 free(temp);}
void printLinkedList(){
 struct Node *temp = head;
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }}
int main(){
 int choice, value, position;
 while (1){
 printf("\n\n----- Single Linked List Operations -----\n");
 printf("1. Insert at beginning\n");
 printf("2. Insert at end\n");
 printf("3. Insert at specific position\n");
 printf("4. Delete from beginning\n");
 printf("5. Delete from end\n");
 printf("6. Delete from specific position\n");
 printf("7. Print linked list\n");
 printf("8. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice){
 case 1:
 printf("Enter value to insert at the beginning: ");
 scanf("%d", &value);
 insertAtBeginning(value);
 break;
 case 2:
 printf("Enter value to insert at the end: ");
 scanf("%d", &value);
 insertAtEnd(value);
 break;
 case 3:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 printf("Enter position to insert at: ");
 scanf("%d", &position);
 insertFromSpecificPosition(value, position);
 break;
 case 4:
 deleteFromBeginning();
 break;
 case 5:
 deleteFromEnd();
 break;
 case 6:
 printf("Enter position to delete from: ");
 scanf("%d", &position);
 deleteFromSpecificPosition(position);
 break;
 case 7:
 printf("Linked list: ");
 printLinkedList();
 break;
 case 8:
 printf("Exiting program.\n");
 exit(0);
 default:
 printf("Invalid choice! Please enter a valid option.\n");} }
 return 0;}
