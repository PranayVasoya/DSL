#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* createlist(int n) {
    struct node* head = NULL;
    struct node* temp = NULL;
    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        struct node* newnode = create(data);
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* deletefirst(struct node* head) {
    if (head == NULL) {
        printf("EMPTY");
    } else {
        struct node* newhead = head->next;
        free(head);
        return newhead;
    }
}

void deletelast(struct node** head) {
    if (*head == NULL) {
        printf("EMPTY");
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deletenth(struct node** head, int n) {
    if (*head == NULL) {
        printf("EMPTY");
    }
    if (n == 1) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    struct node* current = *head;
    struct node* prev = NULL;
    int count = 1;
    while (current != NULL && count < n) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("NODE DOESN'T EXIST");
    } else {
        prev->next = current->next;
        free(current);
    }
}

void addfirst(struct node** head, int data) {
    struct node* newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}

void addlast(struct node** head, int data) {
    struct node* newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void addnth(struct node** head, int data, int n) {
    struct node* newnode = create(data);
    if (n == 1) {
        newnode->next = *head;
        *head = newnode;
    } else {
        struct node* temp = *head;
        struct node* prev = NULL;
        int count = 1;
        while (temp != NULL && count < n) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count == n) {
            prev->next = newnode;
            newnode->next = temp;
        } else {
            printf("Invalid position\n");
        }
    }
}

struct node* mergelists(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct node* mergelist = NULL;
    if (list1->data < list2->data) {
        mergelist = list1;
        mergelist->next = mergelists(list1->next, list2);
    } else {
        mergelist = list2;
        mergelist->next = mergelists(list1, list2->next);
    }
    return mergelist;
}

void reverse(struct node** head) {
    struct node* prevnode = NULL;
    struct node* currentnode = *head;
    struct node* nextnode = NULL;
    while (currentnode != NULL) {
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    *head = prevnode;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, n, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a list\n");
        printf("2. Delete first\n");
        printf("3. Delete last\n");
        printf("4. Delete nth\n");
        printf("5. Add first\n");
        printf("6. Add last\n");
        printf("7. Add nth\n");
        printf("8. Merge lists\n");
        printf("9. Reverse list\n");
        printf("10. Display list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createlist(n);
                break;
            case 2:
                head = deletefirst(head);
                break;
            case 3:
                deletelast(&head);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deletenth(&head, pos);
                break;
            case 5:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addfirst(&head, data);
                break;
            case 6:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addlast(&head, data);
                break;
            case 7:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                addnth(&head, data, pos);
                break;
            case 8:
                // Merge Lists
                break;
            case 9:
                reverse(&head);
                break;
            case 10:
                display(head);
                break;
            case 11:
                printf("Exit.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
