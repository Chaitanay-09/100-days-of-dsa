#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x, int n)
{
    if(size == n)
        return;

    rear = (rear + 1) % n;
    queue[rear] = x;
    size++;
}

int dequeue(int n)
{
    int x = queue[front];
    front = (front + 1) % n;
    size--;
    return x;
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        x = dequeue(n);
        enqueue(x, n);   // circular rotation
    }

    for(i = 0; i < n; i++)
    {
        int index = (front + i) % n;
        printf("%d ", queue[index]);
    }

    return 0;
}