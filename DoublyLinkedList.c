#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;

void insert_begin(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insert_end(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void insert_middle(int data, int position) {
    if (position <= 1) {
        insert_begin(data);
        return;
    }

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        insert_end(data);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

int delete_begin() {
    if (head == NULL) return -1;
    struct Node* temp = head;
    int val = temp->data;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return val;
}

int delete_end() {
    if (head == NULL) return -1;
    struct Node* temp = head;
    if (temp->next == NULL) {
        int val = temp->data;
        free(temp);
        head = NULL;
        return val;
    }
    while (temp->next != NULL)
        temp = temp->next;
    int val = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return val;
}

int delete_middle(int position) {
    if (head == NULL) return -1;
    if (position == 1) return delete_begin();

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return -1;
    int val = temp->data;

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    return val;
}

void display() {
    struct Node* temp = head;
    printf("\nList (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverse_display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("\nList is empty.");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("\nList (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

void search(int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nElement %d found.", key);
            return;
        }
        temp = temp->next;
    }
    printf("\nElement %d not found.", key);
}

int main() {
    int choice, ele, pos;

    while (1) {
        printf("\n\n1.Insert at beginning\n2.Insert at middle\n3.Insert at end");
        printf("\n4.Delete at beginning\n5.Delete at middle\n6.Delete at end");
        printf("\n7.Display\n8.Reverse Display\n9.Search\n10.Exit");
        printf("\nEnter your choice: ");
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
                ele = delete_begin();
                if (ele == -1)
                    printf("List is empty.");
                else
                    printf("Deleted: %d", ele);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                ele = delete_middle(pos);
                if (ele == -1)
                    printf("Invalid position.");
                else
                    printf("Deleted: %d", ele);
                break;
            case 6:
                ele = delete_end();
                if (ele == -1)
                    printf("List is empty.");
                else
                    printf("Deleted: %d", ele);
                break;
            case 7:
                display();
                break;
            case 8:
                reverse_display();
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                search(ele);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}
