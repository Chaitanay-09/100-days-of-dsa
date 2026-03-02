#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

int main()
{
    int n, i;
    struct Node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}