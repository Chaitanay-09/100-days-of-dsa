#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp, *newNode;
    
    for(int i = 0; i < n; i++)
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
    return head;
}

int getLength(struct Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    if(len1 > len2)
    {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    }
    else
    {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}