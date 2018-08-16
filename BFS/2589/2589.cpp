#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int> >q;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int len[51][51];
int arr[51][51];
char val;
int visit[51][51];
int M, N;
int max_value;

void bfs(int c_x, int c_y){
	visit[c_x][c_y] = 1;
	q.push(make_pair(c_x, c_y));
	
	int x, y;

	while(!q.empty()){
		
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			nx = x + ax[i];
			ny = y + ay[i];
			if(!visit[nx][ny] && arr[nx][ny]){
				visit[nx][ny] = 1;
				len[nx][ny] = len[x][y] + 1;

				q.push(make_pair(nx, ny));
				if(len[nx][ny] > max_value){
					max_value = len[nx][ny];
				}	
			}
		}
	}
}

int main(){
	scanf("%d %d", &M, &N);
	for(int i = 0; i < M; i++){
		getchar();
		for(int j = 0; j < N; j++){
			val = getchar();
			if(val == 'L'){
				arr[i][j] = 1;
			}
			else arr[i][j] = 0;
		}
	}
	for(int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if(arr[i][j] && !visit[i][j]){
				bfs(i, j);
				memset(len, 0, sizeof(len));
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	printf("%d\n", max_value);
}
