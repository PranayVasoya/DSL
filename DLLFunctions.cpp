#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct node* createList() {
    return NULL;
}
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void deleteLastNode(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            *head = NULL;
        }

        free(temp);
        printf("Last node deleted.\n");
    }
}
void deleteNthNode(struct node** head, int n) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct node* temp = *head;
        int count = 1;
        while (temp != NULL && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Node not found.\n");
        } else {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Node at position %d deleted.\n", n);
        }
    }
}
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtNthPosition(struct node** head, int data, int n) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        int count = 1;
        while (temp != NULL && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Node not found.\n");
        } else {
            newNode->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
}
struct node* mergeLists(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    list2->prev = temp;
    return list1;
}
struct node* reverseList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node* current = head;
        struct node* temp = NULL;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            head = current;
            current = current->prev;
        }
        printf("List reversed.\n");
    }
    return head;
}
void displayList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    struct node* list = createList();
    int choice, data, position;
    do {
        printf("\nDLL Menu:\n");
        printf("1. Insert at the End\n");
        printf("2. Delete Last Node\n");
        printf("3. Delete Node at Nth Position\n");
        printf("4. Insert at the Beginning\n");
        printf("5. Insert at Nth Position\n");
        printf("6. Merge Lists\n");
        printf("7. Reverse List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                break;
            case 2:
                deleteLastNode(&list);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNthNode(&list, position);
                break;
            case 4:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&list, data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtNthPosition(&list, data, position);
                break;
            case 6:
                printf("Enter the number of nodes for the second list: ");
                int n;
                struct node* list2 = createList();
                printf("Enter data for the second list:\n");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertAtEnd(&list2, data);
                }
                list = mergeLists(list, list2);
                break;
            case 7:
                list = reverseList(list);
                break;
            case 8:
                displayList(list);
                break;
            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);
    return 0;
}
