#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX_CANDIDATES][MAX_NAME_LEN];
    int counts[MAX_CANDIDATES] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        char vote[MAX_NAME_LEN];
        scanf("%s", vote);

        // Check if candidate already exists
        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], vote) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(names[unique], vote);
            counts[unique] = 1;
            unique++;
        } else {
            counts[found]++;
        }
    }

    // Find winner: max votes, lexicographically smallest on tie
    int winnerIdx = 0;
    for (int i = 1; i < unique; i++) {
        if (counts[i] > counts[winnerIdx]) {
            winnerIdx = i;
        } else if (counts[i] == counts[winnerIdx] && strcmp(names[i], names[winnerIdx]) < 0) {
            winnerIdx = i;
        }
    }

    printf("%s %d\n", names[winnerIdx], counts[winnerIdx]);
    return 0;
}