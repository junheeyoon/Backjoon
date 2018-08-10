#include <stdio.h>
int N;
int val[10002];
int Dp[10002];
int max(int x, int y){
	if( x > y ) return x;
	else return y;
}
int main(void) {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &val[i]);
	}
	for(int i = 1; i <= 2; i++){
		if( i == 1 ){
			Dp[i] = val[i];
		}
		else Dp[i] = val[i-1] + val[i];
	}
	for(int i = 3; i <= N; i++){
		Dp[i] = max(Dp[i-1],max(Dp[i-2]+val[i],val[i-1]+val[i]+Dp[i-3]));
	}
	
	printf("%d\n", Dp[N]);
	return 0;
}
