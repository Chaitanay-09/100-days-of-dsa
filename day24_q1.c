#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i;
    struct Node *head = NULL, *temp = NULL, *newNode, *prev;

    scanf("%d", &n);

    // Creating linked list
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    temp = head;
    prev = NULL;

    // Delete first occurrence
    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // Print linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}