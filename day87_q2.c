#include <math.h>

// Check if Koko can finish all bananas at speed k within h hours
int canFinish(int* piles, int pilesSize, int k, int h) {
    long long hours = 0;
    for (int i = 0; i < pilesSize; i++)
        hours += (piles[i] + k - 1) / k;  // ceil(piles[i] / k)
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    // Search space: [1, max(piles)]
    int low = 1, high = 0;
    
    // Find max pile
    for (int i = 0; i < pilesSize; i++)
        if (piles[i] > high)
            high = piles[i];
    
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canFinish(piles, pilesSize, mid, h)) {
            result = mid;    // mid works, try slower
            high = mid - 1;
        } else {
            low = mid + 1;   // too slow, try faster
        }
    }
    
    return result;
}