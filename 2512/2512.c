#include <stdio.h>
int H[10001];
int main(void) {
	// your code goes here
	int left = 0;
	int right = 0;
	int mid;
	int total;
	int N, limit;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &H[i]);
		if(H[i] > right){
			right = H[i];
		}
	}
	scanf("%d", &limit);
	while(left <= right){
		total = 0;
		mid = (left + right) / 2;
		for(int i = 0; i < N; i++){
			if(H[i] > mid){
				total += mid;
			}
			else total += H[i];
		}
		if(total > limit){
			right = mid -1;
		}
		else left = mid + 1;
	}
	printf("%d", right);
	return 0;
}
