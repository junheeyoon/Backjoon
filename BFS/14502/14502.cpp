#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int> >q;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int N, M;
int arr[10][10];
int copy_a[10][10];
int max_value;
int visit[10][10];
int cnt;

void copy_array(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			copy_a[i][j] = arr[i][j];
			if(copy_a[i][j] == 1 || copy_a[i][j] == 2){
				visit[i][j] = 1;
			}
			if(copy_a[i][j] == 2){
				q.push(make_pair(i, j));
			}
		}
	}
}

void bfs(){
	int count = 0;
	int x, y;
	
	copy_array();
	
	while(!q.empty()){

		x = q.front().first;
		y = q.front().second;
		
		visit[x][y] = 1;
		
		q.pop();

		for(int i = 0; i < 4; i++){
			nx = x + ax[i];
			ny = y + ay[i];
		
			if(!copy_a[nx][ny] && !visit[nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < M){
				q.push(make_pair(nx, ny));
				visit[nx][ny] = 1;
			}
		}
	}
	for(int k = 0; k < N; k++){
		for(int l = 0; l < M; l++){
			if(visit[k][l] == 0)
				count++;
		}
	}
	if(max_value < count){
		max_value = count;
	}
}

void wall(int cnt){
	if(cnt == 3){
		bfs();
		cnt--;
		memset(copy_a, 0, sizeof(copy_a));
		memset(visit, 0, sizeof(visit));
		return;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(arr[i][j] == 0){
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;				
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	wall(cnt);
	printf("%d\n ", max_value);
}
