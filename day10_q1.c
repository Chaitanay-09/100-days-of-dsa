#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    int palindrome = 1;

    while (left < right) {
        if (s[left] != s[right]) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (palindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
