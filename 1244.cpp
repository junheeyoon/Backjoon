#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int> >q;
int N, M;
int arr[301][301];
int visit[301][301];
int copy_array[301][301];
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int cnt;
int time_value;
int max_value;
void dfs(int x, int y){
	visit[x][y] = 1;
	for(int i = 0; i < 4; i++){			
		nx = x + ax[i];
		ny = y + ay[i];
		if(!visit[nx][ny] && arr[nx][ny]){
			visit[nx][ny] = 1;
			dfs(nx, ny); 
		}
	}
}
void melt(int x, int y){
	
	for(int i = 0; i < 4; i++){
			
		nx = x + ax[i];
		ny = y + ay[i];

		if(!copy_array[nx][ny] && arr[x][y]){
			arr[x][y]--;				
		}
	}		
}

int main(){
	int t = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	while(1){
		cnt = 0;
		t++;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				copy_array[i][j] = arr[i][j];
			}
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(arr[i][j]){
					melt(i,j);
				}
			}
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(arr[i][j] && !visit[i][j]){
					dfs(i,j);
					cnt++;	
				}
			}
		}
		if(cnt == 0){
			break;
		}
		
		if(cnt > 1){
			printf("%d\n", t);
			return 0;
		}
		memset(visit, 0, sizeof(visit));
	}

	printf("0\n");
	return 0;
}