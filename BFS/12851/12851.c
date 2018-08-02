#include <stdio.h>
int N, K;
int queue[2500000];
int visit[100001];
int cnt = -1;
int front = -1;
int end = -1;
int minimum = 1000001;
int sec = 0;
int f;
int e;
int temp = 0;
void bfs(){
	
	queue[++end] = N;
	visit[N] = 1;
	while(front < end){
		cnt++;
		front = temp;

		f = front;
		e = end;
		for(int j = f; j <= e; j++){

			int val = queue[j];
			visit[val] = 1;
			
			if(K == val){
				sec++;
				if(cnt < minimum){
					minimum = cnt;
				}
				
			}
			if(val - 1 >= 0 && visit[val-1] == 0){
				queue[++end] = val - 1;
			}
			if(val + 1 <= 100000 && visit[val+1] == 0){
				queue[++end] = val + 1;
			}
			if(val * 2 <= 100000 && visit[val*2] == 0){
				queue[++end] = val * 2;
			}
		}
		if(sec) return;
		temp = e + 1;

	}
}
int main(void) {
	
	scanf("%d %d", &N, &K);
	if(N == K){
		printf("0\n1"); 
	}
	else{ 
		bfs();
		printf("%d\n%d", cnt, sec);
	}
	return 0;
}
