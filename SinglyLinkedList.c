#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};
struct node* head = NULL;
// Insert at the front
void insert_front(int e) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = e;
    new_node->link = head;
    head = new_node;
}
// Insert at a specific position (1-based index)
void insert_middle(int e, int n) {
    if (n <= 1 || head == NULL) {
        insert_front(e);
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < n - 1 && temp->link != NULL; i++) {
        temp = temp->link;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = e;
    new_node->link = temp->link;
    temp->link = new_node;
}

// Insert at the end
void insert_end(int e) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = e;
    new_node->link = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;
}

// Delete from the front
void delete_front() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->link;
    printf("%d is deleted from SLL\n", temp->data);
    free(temp);
}

// Delete from a specific position
void delete_middle(int n) {
    if (head == NULL || n <= 1) {
        delete_front();
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < n - 1 && temp->link != NULL; i++) {
        temp = temp->link;
    }

    if (temp->link == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node* temp1 = temp->link;
    temp->link = temp1->link;
    printf("%d is deleted from position %d\n", temp1->data, n);
    free(temp1);
}

// Delete from the end
void delete_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->link == NULL) {
        printf("%d is deleted from SLL\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    printf("%d is deleted from SLL\n", temp->data);
    prev->link = NULL;
    free(temp);
}

// Display the list
void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Search for an element
void search(int e) {
    struct node* temp = head;
    int i = 1;
    while (temp != NULL) {
        if (temp->data == e) {
            printf("Element present at position %d\n", i);
            return;
        }
        temp = temp->link;
        i++;
    }
    printf("Element not present\n");
}

// Main function
int main() {
    int choice, e, n;

    for (;;) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Middle\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Middle\n");
        printf("6. Delete from End\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert at front: ");
            scanf("%d", &e);
            insert_front(e);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &e);
            printf("Enter the position: ");
            scanf("%d", &n);
            insert_middle(e, n);
            break;
        case 3:
            printf("Enter the element to insert at end: ");
            scanf("%d", &e);
            insert_end(e);
            break;
        case 4:
            delete_front();
            break;
        case 5:
            printf("Enter the position to delete: ");
            scanf("%d", &n);
            delete_middle(n);
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter the element to search: ");
            scanf("%d", &e);
            search(e);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
