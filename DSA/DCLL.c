#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* prev;
 struct Node* next;
};
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}
//insertion 
void insertAtBeginning(struct Node** head, int data) {
 struct Node* newNode = createNode(data);
 if (*head == NULL) {
 newNode->next = newNode;
 newNode->prev = newNode;
 } else {
 newNode->next = *head;
 newNode->prev = (*head)->prev;
 (*head)->prev->next = newNode;
 (*head)->prev = newNode;
 }
 *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
 if (*head == NULL) {
 insertAtBeginning(head, data);
 return;
 }
 struct Node* newNode = createNode(data);
 newNode->next = *head;
 newNode->prev = (*head)->prev;
 (*head)->prev->next = newNode;
 (*head)->prev = newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
 if (position <= 0) {
 insertAtBeginning(head, data);
 return;
 }
 struct Node* newNode = createNode(data);
 struct Node* current = *head;
 int currentPosition = 1;
 while (current != NULL && currentPosition < position) {
 current = current->next;
 currentPosition++;
 }
 if (current == NULL) {
 printf("Position is out of range.\n");
 return;
 }
 newNode->prev = current;
 newNode->next = current->next;
 if (current->next != NULL) {
 current->next->prev = newNode;
 }
 current->next = newNode;}
//Deletion
void deleteNode(struct Node** head, int key) {
 if (*head == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = *head;
 while (temp->data != key) {
 temp = temp->next;
 if (temp == *head) {
 printf("Element not found in the list.\n");
 return; } }
 if (temp->next == temp) {
 *head = NULL;
 } else {
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 if (temp == *head) {
 *head = temp->next;
 }
}
 free(temp);}
void displayData(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return; }
 struct Node* current = head;
 do {
 printf("%d ", current->data);
 current = current->next;
 } while (current != head);
 printf("\n");
}
int main() {
 struct Node* head = NULL;
 int choice, data, position;
 do {
 printf("\nDoubly Circular Linked List Operations:\n");
 printf("1. Insert at the beginning\n");
 printf("2. Insert at the end\n");
 printf("3. Insert at a specific position\n");
 printf("4. Delete a node\n");
 printf("5. Display the list\n");
 printf("6. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the data to insert at the beginning: ");
 scanf("%d", &data);
 insertAtBeginning(&head, data);
 break;
 case 2:
 printf("Enter the data to insert at the end: ");
 scanf("%d", &data);
 insertAtEnd(&head, data);
 break;
 case 3:
 printf("Enter the data to insert: ");
 scanf("%d", &data);
 printf("Enter the position to insert at: ");
 scanf("%d", &position);
 insertAtPosition(&head, data, position);
 break;
 case 4:
 printf("Enter the data of the node to delete: ");
 scanf("%d", &data);
 deleteNode(&head, data);
 break;
 case 5:
 printf("Doubly Circular linked list: ");
 displayData(head);
 break;
 case 6:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice, please try again.\n");
 } } while (choice != 6);
 return 0
;
}
