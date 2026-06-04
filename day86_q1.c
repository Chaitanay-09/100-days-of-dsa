#include <stdio.h>

int integerSquareRoot(int n) {
    if (n == 0 || n == 1) return n;
    
    int low = 0, high = n, ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (mid <= n / mid) {  // mid * mid <= n (avoids overflow)
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", integerSquareRoot(n));
    return 0;
}