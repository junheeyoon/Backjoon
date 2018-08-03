#include <stdio.h>
int maxDp[100001][3];
int minDp[100001][3];
int check[3];
int maxValue;
int minValue;
int min(int a, int b){
	if( a > b ) return b;
	else return a;
}
int max(int a, int b){
	if( a > b ) return a;
	else return b;
}
int main(void) {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d %d", &check[0], &check[1], &check[2]);
		
		maxDp[i][0] = max(maxDp[i-1][0], maxDp[i-1][1]) + check[0];
		maxDp[i][1] = max(max(maxDp[i-1][0], maxDp[i-1][1]), maxDp[i-1][2])  + check[1];
		maxDp[i][2] = max(maxDp[i-1][1], maxDp[i-1][2]) + check[2];
		
		minDp[i][0] = min(minDp[i-1][0], minDp[i-1][1]) + check[0];
		minDp[i][1] = min(min(minDp[i-1][0], minDp[i-1][1]), minDp[i-1][2])  + check[1];
		minDp[i][2] = min(minDp[i-1][1], minDp[i-1][2]) + check[2];
		
	}
	maxValue = max(max(maxDp[N][0], maxDp[N][1]), maxDp[N][2]);
	minValue = min(min(minDp[N][0], minDp[N][1]), minDp[N][2]);
	printf("%d %d\n", maxValue, minValue);
	return 0;
}
