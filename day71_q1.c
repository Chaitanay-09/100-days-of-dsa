#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int *table;
int m;

int hash(int k) {
    return k % m;
}

void insert(int k) {
    for (int i = 0; i < m; i++) {
        int pos = (hash(k) + i * i) % m;
        if (table[pos] == EMPTY || table[pos] == DELETED) {
            table[pos] = k;
            return;
        }
    }
}

void search(int k) {
    for (int i = 0; i < m; i++) {
        int pos = (hash(k) + i * i) % m;
        if (table[pos] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
        if (table[pos] == k) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    scanf("%d", &m);
    table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    int q;
    scanf("%d", &q);

    while (q--) {
        char op[10];
        int val;
        scanf("%s %d", op, &val);
        if (strcmp(op, "INSERT") == 0) insert(val);
        else if (strcmp(op, "SEARCH") == 0) search(val);
    }

    free(table);
    return 0;
}