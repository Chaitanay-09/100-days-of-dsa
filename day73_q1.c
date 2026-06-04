#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    
    int freq[26] = {0};
    int n = strlen(s);
    
    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    
    printf("$\n");
    return 0;
}