#include <stdio.h>
long long int Dp[101][21];
int arr[101];
int main(void) {
	int N;
	int a, b;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}
	Dp[1][arr[1]] = 1;
	
	for(int i = 1; i <= N-1; i++){
		for(int j = 0; j < 21; j++){
			if(Dp[i][j]){
				a = j + arr[i+1];
				b = j - arr[i+1];
				if(a >= 0 && a <= 20){
					Dp[i+1][a] += Dp[i][j];
				}
				if(b >= 0 && b <= 20){
					Dp[i+1][b] += Dp[i][j];
				}
			}
		}
	}
	printf("%lld\n", Dp[N-1][arr[N]]);
	return 0;
}
