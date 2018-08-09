#include <stdio.h>
int ax[4] = { 0, 0, -1, 1};
int ay[4] = { 1, -1, 0, 0};
int T;
int K;
int M, N;
int a, b;
int nx, ny;
int cnt;
int arr[51][51];
int visit[51][51];

void bfs(int x, int y){
	visit[x][y] = 1;
	if(x < 0 || y < 0 || x >= M || y >= N)	return;
	for(int i = 0; i < 4; i++){
		nx = x + ax[i];
		ny = y + ay[i];
		if(visit[nx][ny] == 0 && arr[nx][ny] == 1){
			bfs(nx, ny);
		}
	}
}

int main(void) {
	scanf("%d", &T);
	while(T--){
		cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for(int i = 0; i < K; i++){
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}
		
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(arr[i][j] == 1 && visit[i][j] == 0){
					bfs(i,j);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	return 0;
}
