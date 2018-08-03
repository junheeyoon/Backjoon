#include <stdio.h>
int N, K;
int queue[250000];
int visit[100001];
int d[100001];
int front = -1;
int end = -1;
int bfs(){
	queue[++end] = N;
	visit[N] = 1;
	while(front < end){
		int val = queue[++front];
		if(val * 2 <= 100000 && visit[val*2] == 0){
			queue[++end] = val * 2;
			visit[val * 2] = 1;
			d[val*2] = d[val];
		}
		if(queue[end] == K) break;
		if(val - 1 >= 0 && visit[val-1] == 0){
			queue[++end] = val - 1;
			visit[val - 1] = 1;
			d[val-1] = d[val] + 1;
		}
		if(queue[end] == K) break;
		if(val + 1 <= 100000 && visit[val+1] == 0){
			queue[++end] = val + 1;
			visit[val + 1] = 1;
			d[val+1] = d[val] + 1;
		}
		if(queue[end] == K) break;
	}
	return d[K];
}
int main(void) {
	
	scanf("%d %d", &N, &K);
	if(N == K){
		printf("0\n"); 
	}
	else printf("%d\n", bfs());
	return 0;
}
