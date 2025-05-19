#include <cstdio> // For printf and scanf
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;            // Value of the node
    ListNode* next;     // Pointer to the next node

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with a value and next pointer
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr; // Head of the resulting list
    ListNode* tail = nullptr; // Tail pointer to append nodes
    int carry = 0;            // Carry from sum

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        ListNode* newNode = new ListNode(sum);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to create a linked list from user input
ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x); // Read an integer
        ListNode* newNode = new ListNode(x);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;

    // Input for the first list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    printf("Enter values (in reverse order): ");
    ListNode* l1 = createList(n1);

    // Input for the second list
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);
    printf("Enter values (in reverse order): ");
    ListNode* l2 = createList(n2);

    // Add two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Output result list
    printf("Sum list: ");
    printList(result);

    return 0;
}
