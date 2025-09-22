#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
} *top = NULL;
// Function to push an item onto the stack
void push(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = top;  // Link the new node to the current top
    top = newnode;        // Update the top to the new node
}
// Function to pop an item from the stack
void pop() {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        struct node *temp = top;
        top = top->next;  // Move top to the next element
        free(temp);       // Free the memory of the popped element
    }
}

// Function to peek at the top item of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display the stack elements
void display() {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        struct node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice = 0, item;

    while (choice != 6) {
        printf("\n1. Check if stack is empty\n2. Push\n3. Pop\n4. Peek\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == NULL)
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;

            case 2:
                printf("Enter element to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;

            case 3:
                pop();
                break;

            case 4:
                peek();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Enter correct choice\n");
        }
    }

    return 0;
}
