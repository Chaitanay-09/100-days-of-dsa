#include <stdio.h>

int main() {
    int n, i;
    
    // Input size
    scanf("%d", &n);
    
    int queue[n], stack[n];

    // Input queue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    // Push queue elements into stack
    for(i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    // Pop stack elements back to queue (reversing)
    for(i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}