#include <cstdio>
#include <queue>
using namespace std;
queue<pair<int, int> > q;

int arr[301][301];
int visit[301][301];
int N;
int array_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int array_y[8] = {-1, 1, -2, 2, 2, -2, 1, -1};
int next_x, next_y;
int t;
int start_x, start_y;
int end_x, end_y;

void night(int x, int y){
	if(x < 0 || y < 0 || x >= N || y >= N){
			return;
	}
	while(!q.empty()){
		for(int i = 0; i < 8; i++){
			next_x = x + array_x[i];
			next_y = y + array_y[i];
			
			if(!visit[next_x][next_y] && next_x >= 0 && next_y >= 0 && next_x < N && next_y < N){

				visit[next_x][next_y] = visit[x][y] + 1;
				q.push(make_pair(next_x, next_y));			
			}
		}
		q.pop();
		night(q.front().first, q.front().second);
	}
}

int main(){
	
	scanf("%d", &t);
	while(t--){
		for(int m = 0; m < N; m++){
			for(int n = 0; n < N; n++){
				arr[m][n] = 0;
				visit[m][n] = 0;
			}
		}
		scanf("%d %d %d %d %d", &N, &start_x, &start_y, &end_x, &end_y);
		arr[start_x][start_y] = 1;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(arr[i][j] && !visit[i][j]){
					visit[i][j] = 1;
					q.push(make_pair(i, j));
					night(i, j);
				}
			}
		}
		printf("%d\n", visit[end_x][end_y] - 1);
	}
	
}
