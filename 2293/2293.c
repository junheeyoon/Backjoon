#include <stdio.h>
Dp[10001] = {0, };
int main(void) {
    int n, k;
    int a[101];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    Dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= k; j++){
            if(j >= a[i]){
                Dp[j] += Dp[j-a[i]];
            }
        }
    }
    printf("%d\n", Dp[k]);
    return 0;
}
