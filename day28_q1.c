#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make circular
    temp->next = head;

    // Traversal
    struct Node *ptr = head;

    if(head != NULL)
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        while(ptr != head);
    }

    return 0;
}