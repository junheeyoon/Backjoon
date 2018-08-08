#include <stdio.h>
typedef struct _Point{
	int x;
	int y;
}Point;

Point queue[1000001];
int M,N;
int last;
int arr[1001][1001];
int visit[1001][1001];
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int cnt;
int current;
int max = 0;

void bfs(int x, int y){

	if(x < 0 || y < 0 || x >= N || y >= M) return;
	
	for(int i = 0; i < 4; i++){
		nx = x + ax[i];
		ny = y + ay[i];
		if(visit[nx][ny] == 0){
			visit[nx][ny] = visit[x][y] + 1;
			queue[current].x = nx;
			queue[current].y = ny;
			current++;
		}
	}
	
    ++last;
	if(last <= current){
		bfs(queue[last].x, queue[last].y);
	}
}

int main(void) {
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1){
				visit[i][j] = 1;
				queue[current].x = i;
				queue[current].y = j;
				current++;
			}
			if(arr[i][j] == -1){
				visit[i][j] = -1;
			}
		}
    }
    
	for(int i = 0; i < current; i++){
		bfs(queue[i].x, queue[i].y);
	}
    
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(visit[i][j] == 0){
				printf("-1\n");
				return 0;
			}
			if(max < visit[i][j]){
				max = visit[i][j];
			}
		}
	}
    
	printf("%d\n", max-1);
	return 0;
}