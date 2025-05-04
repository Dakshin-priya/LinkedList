#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isempty() {
    if (front == NULL)
        return 1;  // Queue is empty
    else
        return 0;  // Queue is not empty
}

void enqueue(int item) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if (front == NULL) {
        // If the queue is empty, both front and rear should point to the new node
        front = newnode;
        rear = newnode;
    } else {
        // If the queue is not empty, add the new node to the end and move rear to it
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (isempty() == 1)
        printf("Queue is empty\n");
    else {
        struct node *temp = front;
        front = front->next;  // Move front to the next element
        free(temp);  // Free the old front node
    }
}

void display() {
    if (isempty() == 1)
        printf("Queue is empty\n");
    else {
        struct node *temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice = 0, item;

    while (choice != 5) {
        printf("\n1. Check if queue is empty\n2. Enqueue\n3. Dequeue\n4. Display queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isempty() == 1)
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 2:
                printf("Enter element to be enqueued: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 3:
                dequeue();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Enter a correct choice\n");
        }
    }

    return 0;
}
