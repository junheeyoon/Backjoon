#include <stdio.h>
int arr[102][102];
int visit[102][102];
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int N;
int cnt;
int max;
int cnt_max = 1;
int min = 987654321;

void dfs(int x, int y, int h){
	if(x < 0 || y < 0 || x >= N || y >= N){
		return;
	}
	if(visit[x][y] || arr[x][y] <= h){
		return;
	}
	visit[x][y] = 1;
	for(int k = 0; k < 4; k++){
		nx = ax[k] + x;
		ny = ay[k] + y;
		
		dfs(nx, ny, h);			
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
			if(min > arr[i][j]){
				min = arr[i][j];
			}
			if(arr[i][j] > max){
				max = arr[i][j];
			}
		}
	}

	for(int i = min; i < max; i++){

		cnt = 0;
		for(int m = 0; m < N; m++){
			for(int n = 0; n < N; n++){
				visit[m][n] = 0;
			}
		}
		for(int k = 0; k < N; k++){
			for(int j = 0; j < N; j++){
				if(visit[k][j] == 0 && arr[k][j] > i){
					dfs(k, j, i);
					cnt++;
				}
			}
		}
		if(cnt_max < cnt){
			cnt_max = cnt;
		}
		
	}
	printf("%d\n", cnt_max);
}