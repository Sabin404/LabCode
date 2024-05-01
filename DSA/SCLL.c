#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;}
//insertion 
void insertAtBeginning(struct Node** head, int data) {
 struct Node* newNode = createNode(data);
 if (*head == NULL) {
 newNode->next = newNode; // Pointing to itself
 *head = newNode;
 } else {
 struct Node* current = *head;
 while (current->next != *head) {
 current = current->next;
 }
 current->next = newNode;
 newNode->next = *head;
 *head = newNode; }}
void insertAtEnd(struct Node** head, int data) {
 struct Node* newNode = createNode(data);
 if (*head == NULL) {
 newNode->next = newNode; // Pointing to itself
 *head = newNode;
 } else {
 struct Node* current = *head;
 while (current->next != *head) {
 current = current->next;
 }
 current->next = newNode;
 newNode->next = *head;
 }
}
void insertAtPosition(struct Node** head, int data, int position) {
 if (position <= 0) {
 printf("Invalid position.\n");
 return; }
 if (*head == NULL || position == 1) {
 insertAtBeginning(head, data);
 return;
 }
 struct Node* newNode = createNode(data);
 struct Node* current = *head;
 int currentPosition = 1;
 while (current->next != *head && currentPosition < position - 1) {
 current = current->next;
 currentPosition++;
 }
 newNode->next = current->next;
 current->next = newNode;
}
//deletion 
void deleteNode(struct Node** head, int key) {
 if (*head == NULL) {
 printf("List is empty.\n");
 return; }
 struct Node *temp = *head, *prev = NULL;
 if (temp->data == key) {
 while (temp->next != *head)
 temp = temp->next;
 temp->next = (*head)->next;
 free(*head);
 *head = temp->next;
 return;
 }
 while (temp->next != *head && temp->data != key) {
 prev = temp;
 temp = temp->next;
 }
 if (temp->data != key) {
 printf("Key not found in the list.\n");
 return;
 }
 prev->next = temp->next;
 free(temp);}
void displayData(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return;
 }
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
 printf("\nSingly Circular Linked List Operations:\n");
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
 printf("Singly Circular linked list: ");
 displayData(head);
 break;
 case 6:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice, please try again.\n"); }
 } while (choice != 6); 
return 0
}
