#include <stdio.h>
int Dp[1001];	
int main(void) {
	int N;
	scanf("%d", &N);
	Dp[1] = 1;
	Dp[2] = 3;
	for(int i = 3; i <= N; i++){
		Dp[i] = (Dp[i-1] + Dp[i-2]*2) % 10007;
	}
	printf("%d", Dp[N]);
	return 0;
}
