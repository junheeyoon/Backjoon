#include <stdio.h>
#define mod 1000000000

int val[210][210];

int main(void) {
	int N,K;
	scanf("%d %d", &N, &K);

	for(int i = 0; i <= N; i++){
			val[1][i] = 1;
	}
	

	for(int i = 0; i <= N; i++){
			val[2][i] = i+1;
	}
	
	for(int i = 3; i <= K; i++){
		for(int j = 0; j <= N; j++){
			for(int k = 0; k <= j; k++){
				val[i][j] = (val[i][j] + val[i-1][k]) % mod;
			}
		}	
	}
	
	printf("%d\n", val[K][N] % mod);
	return 0;
}
