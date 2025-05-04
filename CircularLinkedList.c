#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int element) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;

    if (head == NULL) {
        newnode->next = newnode; // circular
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_end(int element) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_middle(int element, int pos) {
    if (pos <= 1) {
        insert_begin(element);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    struct node *temp = head;

    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

int delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int data;
    if (head->next == head) {
        data = head->data;
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        struct node *del = head;
        data = del->data;
        head = head->next;
        temp->next = head;
        free(del);
    }
    return data;
}

int delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int data;
    if (head->next == head) {
        data = head->data;
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        struct node *prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        data = temp->data;
        free(temp);
    }
    return data;
}

int delete_middle(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    if (pos == 1)
        return delete_begin();

    struct node *temp = head;
    struct node *prev = NULL;
    int count = 1;

    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Invalid position\n");
        return -1;
    }

    prev->next = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void search(int element) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    int pos = 1;
    do {
        if (temp->data == element) {
            printf("Element %d found at position %d\n", element, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element not found\n");
}

int main() {
    int choice, ele, pos;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at middle\n3. Insert at end\n4. Delete at beginning\n5. Delete at middle\n6. Delete at end\n7. Display\n8. Search\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert_begin(ele);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_middle(ele, pos);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert_end(ele);
                break;
            case 4:
                printf("Deleted element: %d\n", delete_begin());
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                printf("Deleted element: %d\n", delete_middle(pos));
                break;
            case 6:
                printf("Deleted element: %d\n", delete_end());
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                search(ele);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
