#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the linked list
void addToBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the linked list
void addToEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}



// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}



// Function to merge two linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct Node* concatenateList = NULL;
    if (list1->data < list2->data) {
        concatenateList = list1;
        concatenateList->next = concatenateLists(list1->next, list2);
    } else {
        concatenateList = list2;
        concatenateList->next = concatenateLists(list1, list2->next);
    }
    return concatenateList;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



// Function to reverse a linked list
void reverseList(struct Node** head) {
    struct Node* prevNode = NULL;
    struct Node* currentNode = *head;
    struct Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next; // Store the next node
        currentNode->next = prevNode; // Change next of temp node
        prevNode = currentNode;       // Move prev to the temp node
        currentNode = nextNode;       // Move temp to the next node
    }

    *head = prevNode; // Update the head to the last node (new start of the list)
}

// Prints the operations menu
void printMenu() {
    printf("\nSingle Linked List Operations:\n");
    printf("1. Add Node to List 1 (Beginning)\n");
    printf("2. Add Node to List 1 (End)\n");
    printf("3. Delete First Node from List 1\n");
    printf("4. Delete Last Node from List 1\n");
    printf("5. Reverse List 1\n");
    printf("6. Print List 1\n");
    printf("7. Add Node to List 2 (Beginning)\n");
    printf("8. Add Node to List 2 (End)\n");
    printf("9. Delete First Node from List 2\n");
    printf("10. Delete Last Node from List 2\n");
    printf("11. Reverse List 2\n");
    printf("12. Print List 2\n");
    printf("13. concatenate Lists\n");
    printf("14. Add Node to Merged List (Beginning)\n");
    printf("15. Add Node to Merged List (End)\n");
    printf("16. Delete First Node from Merged List\n");
    printf("17. Delete Last Node from Merged List\n");
    printf("18. Reverse Merged List\n");
    printf("19. Print Merged List\n");
    printf("20. Exit\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* concatenateList = NULL;

    int choice, data, n;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&list1, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&list1, data);
                break;
            case 3:
                deleteFirstNode(&list1);
                printf("First node deleted from List 1.\n");
                break;
            case 4:
                deleteLastNode(&list1);
                printf("Last node deleted from List 1.\n");
                break;
            case 5:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;
            case 6:
                printf("List 1: ");
                printList(list1);
                break;
            case 7:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&list2, data);
                break;
            case 8:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&list2, data);
                break;
            case 9:
                deleteFirstNode(&list2);
                printf("First node deleted from List 2.\n");
                break;
            case 10:
                deleteLastNode(&list2);
                printf("Last node deleted from List 2.\n");
                break;
            case 11:
                reverseList(&list2);
                printf("List 2 reversed.\n");
                break;
            case 12:
                printf("List 2: ");
                printList(list2);
                break;
            case 13:
                concatenateList = concatenateLists(list1, list2);
                printf("Lists merged.\n");
                break;
            case 14:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&concatenateList, data);
                break;
            case 15:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&concatenateList, data);
                break;
            case 16:
                deleteFirstNode(&concatenateList);
                printf("First node deleted from Merged List.\n");
                break;
            case 17:
                deleteLastNode(&concatenateList);
                printf("Last node deleted from Merged List.\n");
                break;
            case 18:
                reverseList(&concatenateList);
                printf("Merged List reversed.\n");
                break;
            case 19:
                printf("Merged List: ");
                printList(concatenateList);
                break;
            case 20:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

