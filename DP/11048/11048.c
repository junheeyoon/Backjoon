#include <stdio.h>
int Dp[1001][1001];
int val[1001][1001];

int max(int a, int b){
	if(a > b) return a;
	else return b;
}
int main(void) {
	int N,K;
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			scanf("%d", &val[i][j]);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			Dp[i][j] = max(Dp[i-1][j], max(Dp[i][j-1], Dp[i-1][j-1])) + val[i][j];
		}
	}
	printf("%d\n", Dp[N][K]);
	return 0;
}
