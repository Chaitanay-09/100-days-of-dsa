#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, i;
    struct Node *head = NULL, *temp = NULL, *newnode, *tail;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Read k
    scanf("%d", &k);

    k = k % n;

    if(k != 0) {
        // Find last node
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;

        // Make circular list
        tail->next = head;

        // Move to (n-k)th node
        temp = head;
        for(i = 1; i < n-k; i++)
            temp = temp->next;

        // New head
        head = temp->next;

        // Break circular link
        temp->next = NULL;
    }

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}