#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    
    // Initialize visited array
    for(int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // Stack for DFS
    int stack[roomsSize];
    int top = -1;

    // Start from room 0
    stack[++top] = 0;
    visited[0] = true;

    while(top != -1) {
        int room = stack[top--];

        // Visit all keys in current room
        for(int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];

            if(!visited[key]) {
                visited[key] = true;
                stack[++top] = key;
            }
        }
    }

    // Check if all rooms are visited
    for(int i = 0; i < roomsSize; i++) {
        if(!visited[i]) return false;
    }

    return true;
}