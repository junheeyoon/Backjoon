#include <stdio.h>
int Dp[10001];
int p[10001];
int max(int a, int b){
	if (a > b){
		return a;
	}
	else return b;
}
int main(void) {
	int N;
	scanf("%d", &N);
	p[0] = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			Dp[i] = max(Dp[i], p[j] + Dp[i-j]);
		}
	}
	printf("%d", Dp[N]);
	return 0;
}
