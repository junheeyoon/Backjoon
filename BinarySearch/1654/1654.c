#include<stdio.h>
long long int H[1000001];
int main(){
	int K;
	int N;
	long long int left = 1;
	long long int right = 0;
	long long int mid;
	int cnt = 0;

	scanf("%d %d", &K, &N);
	for(int i = 0; i < K; i++){
		scanf("%lld", &H[i]);
		if(right < H[i]){
			right = H[i];
		}	
	}
	
	while(left <= right){
		mid = (left + right) / 2;
		cnt = 0;
		
		for(int i = 0; i < K; i++){
			cnt += H[i] / mid;
		}
		if(cnt < N){
			right = mid - 1;
		}
		else{ 
			left = mid + 1;
		}
	}
	printf("%lld\n", right);

}