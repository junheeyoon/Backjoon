#include <stdio.h>
Dp[10001];
int min(int a, int b){
    if( a < b){
        return a;
    }
    else return b;
}
int main(void) {
    int n, k;
    int a[101];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for ( int i = 1; i <= k; i++){
        Dp[i] = 10001;
    }
    Dp[0] = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= k; j++){
            if(j >= a[i]){
                Dp[j] = min(Dp[j], Dp[j-a[i]] + 1);
            }
        }
    }
    if(Dp[k] == 10001){
        printf("-1\n");
    }
    else printf("%d\n", Dp[k]);
    return 0;
}
