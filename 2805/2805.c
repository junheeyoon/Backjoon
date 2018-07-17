#include<stdio.h>

int H[10000001];
int N,M;

int main(){
	
	int left = 1, right = 0;
	long long int mid;
	int sum = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d", &H[i]);
		if(H[i] > right)
			right = H[i];
	}
	while(left <= right){
		sum = 0;
		mid = (left + right) / 2;
		for(int i = 0; i < N && sum <= M; i++)
			if(H[i] > mid)
				sum += H[i] - mid;
		if((sum - M) == 0){
			printf("%d\n", (int)mid);
			return 0;
		}
		else if(sum - M < 0){
			right = mid - 1;	
		}
		else 
			left = mid + 1 ;
	}	
	printf("%d\n", right);
	return 0;
}
