#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to merge two sorted lists
struct Node* merge(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (head1->data <= head2->data) {
            newNode->data = head1->data;
            head1 = head1->next;
        } else {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining nodes
    while (head1 != NULL) {
        result = insert(result, head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        result = insert(result, head2->data);
        head2 = head2->next;
    }

    return result;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL, *merged = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    merged = merge(head1, head2);
    printList(merged);

    return 0;
}