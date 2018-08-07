#include <stdio.h>
#include <stdlib.h> 
int arr[101][101];
int queue[10001];
int cnt;
int N, M, K;
int a, b, c, d;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
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

void bfs(int x, int y){
	
	if(x < 0 || y < 0 || x >= M || y >= N || arr[x][y]){	
		return;
	}
	queue[cnt]++;
	arr[x][y] = 1;
	for(int i = 0; i < 4; i++){
		bfs(x + ax[i], y + ay[i]);
	}
	
}
int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < K; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int k = a; k < c; k++){
			for(int j = b; j < d; j++){
				arr[k][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(!arr[i][j]){
				bfs(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	qsort(queue, cnt, sizeof(int), compare);
	for(int i = 0; i < cnt; i++){
		printf("%d ", queue[i]);
	}
	return 0;
}
