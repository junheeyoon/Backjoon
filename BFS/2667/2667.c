#include <stdio.h>
#include <stdlib.h>
int ax[4] = { 0, 0, -1, 1};
int ay[4] = { 1, -1, 0, 0};

int N;
int nx, ny;
int cnt;
int arr[51][51];
int visit[51][51];
int num[100001];
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
	num[cnt]++;
	visit[x][y] = 1;
	if(x < 0 || y < 0 || x >= N || y >= N)	return;
	for(int i = 0; i < 4; i++){
		nx = x + ax[i];
		ny = y + ay[i];
		if(visit[nx][ny] == 0 && arr[nx][ny] == 1){
			bfs(nx, ny);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(arr[i][j] == 1 && visit[i][j] == 0){
				bfs(i, j);
				cnt++;
			}
		}
	}
	
	printf("%d\n", cnt);
	qsort(num, cnt, sizeof(int), compare);
	for(int i = 0; i < cnt; i++){
		printf("%d\n", num[i]);
	}
	return 0;
}
