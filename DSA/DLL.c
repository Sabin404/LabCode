#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* prev;
 struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->prev = NULL;
 newNode->next = head;
 if (head != NULL)
 head->prev = newNode;
 head = newNode;
}
//Insertion 
void insertAtEnd(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->next = NULL;
 if (head == NULL) {
 newNode->prev = NULL;
 head = newNode; 
 }
 struct Node* temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
 newNode->prev = temp;
}
void insertFromSpecificPosition(int value, int position) {
 if (position < 1) {
 printf("Invalid position. Insertion failed.\n");
 }
 if (position == 1) {
 insertAtBeginning(value);
 
 }
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 struct Node* temp = head;
 for (int i = 1; i < position - 1 && temp != NULL; i++)
 temp = temp->next;
 if (temp == NULL) {
 printf("Invalid position. Insertion failed.\n");
 
 }
 newNode->next = temp->next;
 newNode->prev = temp;
 if (temp->next != NULL)
 temp->next->prev = newNode;
 temp->next = newNode;
}
//Deletion 
void deleteFromBeginning() {
 if (head == NULL) {
 printf("Linked list is empty. Nothing to delete.\n");
 
 }
 struct Node* temp = head;
 head = head->next;
 if (head != NULL)
 head->prev = NULL;
 free(temp);
}
void deleteFromEnd() {
 if (head == NULL) {
 printf("Linked list is empty. Nothing to delete.\n");
 
 }
 struct Node* temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 if (temp->prev != NULL)
 temp->prev->next = NULL;
 else
 head = NULL;
 free(temp);
}
void deleteFromSpecificPosition(int position) {
 if (position < 1 || head == NULL) {
 printf("Invalid position or empty list. Deletion failed.\n");
 
 }
 struct Node* temp = head;
 if (position == 1) {
 head = head->next;
 if (head != NULL)
 head->prev = NULL;
 free(temp);
 
 }
 for (int i = 1; temp != NULL && i < position; i++)
 temp = temp->next;
 if (temp == NULL) {
 printf("Invalid position. Deletion failed.\n");
 }
 if (temp->next != NULL)
 temp->next->prev = temp->prev;
 temp->prev->next = temp->next;
 free(temp);
}
void printData() {
 struct Node* temp = head;
 printf("Forward: ");
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
}
int main() {
 int choice, value, position;
 while (1) {
 printf("\n\n----- Double Linked List Operations -----\n");
 printf("1. Insert at beginning\n");
 printf("2. Insert at end\n");
 printf("3. Insert at specific position\n");
 printf("4. Delete from beginning\n");
 printf("5. Delete from end\n");
 printf("6. Delete from specific position\n");
 printf("7. Print linked list \n");
 printf("8. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
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
 printData();
 break;
 case 8:
 printf("Exiting program.\n");
 exit(0);
 default:
 printf("Invalid choice! Please enter a valid option.\n");
 } }return 0;}
