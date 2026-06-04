#include <stdio.h>
#include <string.h>

#define MAX 100

// Simple hash map using open addressing
typedef struct {
    int key;   // prefix sum
    int value; // index
    int used;
} HashMap;

HashMap map[200200]; // large enough for collision handling
int MAP_SIZE = 200003;

int hashIndex(int key) {
    // Shift to handle negative keys
    return ((key + 100000) % MAP_SIZE + MAP_SIZE) % MAP_SIZE;
}

void insertMap(int key, int value) {
    int idx = hashIndex(key);
    while (map[idx].used && map[idx].key != key) {
        idx = (idx + 1) % MAP_SIZE;
    }
    if (!map[idx].used) {
        map[idx].key   = key;
        map[idx].value = value;
        map[idx].used  = 1;
    }
    // If already exists, don't overwrite (keep earliest index)
}

int searchMap(int key, int* result) {
    int idx = hashIndex(key);
    while (map[idx].used) {
        if (map[idx].key == key) {
            *result = map[idx].value;
            return 1;
        }
        idx = (idx + 1) % MAP_SIZE;
    }
    return 0;
}

int main() {
    int arr[MAX], n = 0;

    // Read until newline / EOF
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    memset(map, 0, sizeof(map));

    // prefix_sum = 0 seen at index -1 (before array starts)
    insertMap(0, -1);

    int prefix = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int prevIdx;
        if (searchMap(prefix, &prevIdx)) {
            int len = i - prevIdx;
            if (len > maxLen)
                maxLen = len;
        } else {
            insertMap(prefix, i);
        }
    }

    printf("%d\n", maxLen);
    return 0;
}