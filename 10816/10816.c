#include <stdio.h>
#include <stdlib.h>

int input[500001];
int sch[500001];
int compare(const void *a, const void *b)   
{
	int num1 = *(int *)a;    
	int num2 = *(int *)b;   

	if (num1 < num2)    
		return -1;      

	if (num1 > num2)    
		return 1;       

	return 0;    
}
int search(int i, int M){
	int left = 0;
	int right = i - 1;
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		
		if(input[mid] < M){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return right+1;
}
int main(void) {
	// your code goes here
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &input[i]);
	}
	qsort(input, N, sizeof(int), compare);
	scanf("%d", &M);
	for (int i = 0; i < M; i++){
		scanf("%d", &sch[i]);
		int one = search(N, sch[i]);
		if(input[one] == sch[i]){
			printf("%d ", search(N ,sch[i] + 1) - one);
		}
		else printf("0 ");
	}
	
	return 0;
}