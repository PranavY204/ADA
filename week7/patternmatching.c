#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int m, n;
    printf("Enter m and n: ");
    scanf("%d%d", &m, &n);
    char s1[m], s2[n];
    fflush(stdin);
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    // printf("%s %s", s1, s2);
    int i = 0, j = 0;
    while (i < n - m + 1){
        if (s1[0] == s2[i]){
            bool found = true;
            while (j < m){
                if (s1[j] != s2[i+j]) found = false;
                j++;
            }
            if (found) printf("Found at %d", i);
        }
        i++;
    }
    return 0;
}
