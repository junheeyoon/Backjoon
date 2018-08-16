#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, pair<int,int> > que;
queue <que> q;

int arr[101][101][101];
int visit[101][101][101];
int M, N, H;
int array_x[6] = {0, 0, -1, 1, 0, 0};
int array_y[6] = {1, -1, 0, 0, 0, 0};
int array_z[6] = {0, 0, 0, 0, -1, 1};
int next_x, next_y, next_z;
int max_value;

void bfs(){

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		for(int i = 0; i < 6; i++){
			next_x = x + array_x[i];
			next_y = y + array_y[i];
			next_z = z + array_z[i];
			
			if(next_x >= 0 && next_y >= 0 && next_z >= 0 && next_x < M && next_y < N && next_z < H){
				if(!visit[next_z][next_x][next_y] && !arr[next_z][next_x][next_y]){
					visit[next_z][next_x][next_y] = visit[z][x][y] + 1;
					q.push(make_pair(next_x, make_pair(next_y, next_z)));			
				}
			}
		}
		q.pop();
		
	}
}

int main(){
	
	scanf("%d %d %d", &N, &M, &H);
	for(int k = 0; k < H; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				scanf("%d", &arr[k][i][j]);
				if(arr[k][i][j] == 1){
					visit[k][i][j] = 1;
					q.push(make_pair(i, make_pair(j, k)));
				}
				if(arr[k][i][j] == -1){
					visit[k][i][j] = -1;
				}
			}
		}
	}
	
	bfs();
	
	for(int k = 0; k < H; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(visit[k][i][j] == 0){
					printf("-1\n");
					return 0;
				}
				if(visit[k][i][j] > max_value){
					max_value = visit[k][i][j];
				}
			}
		}
	}
	printf("%d\n", max_value-1);
	return 0;
}
