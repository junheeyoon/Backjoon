#include <stdio.h>
int N, K;
int arr[100001];
int queue[250000];
int visit[100001];
int d[100001];
int route[100001];
int front = -1;
int end = -1;
int m = 0;
int L;
int bfs(){
	queue[++end] = N;
	visit[N] = 1;
	while(front < end){
		int val = queue[++front];
		if(val - 1 >= 0 && visit[val-1] == 0){
			queue[++end] = val - 1;
			visit[val - 1] = 1;
			d[val-1] = d[val] + 1;
			route[val-1] = val;
		}
		if(queue[end] == K) break;
		if(val + 1 <= 100000 && visit[val+1] == 0){
			queue[++end] = val + 1;
			visit[val + 1] = 1;
			d[val+1] = d[val] + 1;
			route[val+1] = val;
		}
		if(queue[end] == K) break;
		if(val * 2 <= 100000 && visit[val*2] == 0){
			queue[++end] = val * 2;
			visit[val * 2] = 1;
			d[val*2] = d[val] + 1;
			route[val*2] = val;
		}
		if(queue[end] == K) break;
	}
	return d[K];
}
int main(void) {
	
	scanf("%d %d", &N, &K);
	if(N == K){
		printf("0\n%d", K); 
	}
	
	else {
		L = K;
		printf("%d\n", bfs());
		while(1){
			if(m == bfs()){
				break;
			}
			arr[m] = route[L];
			L = route[L]; 
			m++;
		}
		
		for(int i = m-1; i >= 0; i--){
			printf("%d ", arr[i]);
		}
		printf("%d", K);
	}
	return 0;
}
