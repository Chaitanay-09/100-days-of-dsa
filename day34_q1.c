#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    struct node *temp;
    int val;

    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main() {
    char postfix[100];
    int i = 0;
    int a, b, result;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    while(postfix[i] != '\0') {

        if(isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        else if(postfix[i] == '+' || postfix[i] == '-' || 
                postfix[i] == '*' || postfix[i] == '/') {

            b = pop();
            a = pop();

            switch(postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        i++;
    }

    result = pop();
    printf("%d", result);

    return 0;
}