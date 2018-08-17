#include <cstdio>
#include <queue>

using namespace std;
queue<pair<int, int> >q;
int N;
int nomal[101][101];
int sick[101][101];
int n_visit[101][101];
int s_visit[101][101];
int input;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int cnt;
int cnt2;

void n_dfs(int x, int y){

	n_visit[x][y] = 1;
		
	for(int i = 0; i < 4; i++){
		nx = x + ax[i];
		ny = y + ay[i];

		if(nomal[nx][ny] == nomal[x][y] && !n_visit[nx][ny]){
			n_visit[nx][ny] = 1;
			n_dfs(nx, ny);
		}
	}
}
void s_dfs(int x, int y){

	s_visit[x][y] = 1;
		
	for(int i = 0; i < 4; i++){
		nx = x + ax[i];
		ny = y + ay[i];

		if(sick[nx][ny] == sick[x][y] && !s_visit[nx][ny]){
			s_visit[nx][ny] = 1;
			s_dfs(nx, ny);
		}
	}
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		getchar();
		for(int j = 0; j < N; j++){
			input = getchar();
			if(input == 'R'){
				nomal[i][j] = 1;
				sick[i][j] = 1;
			}
			else if(input == 'B'){
				nomal[i][j] = 2;
				sick[i][j] = 2;
			}
			else{ 
				nomal[i][j] = 3;
				sick[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!n_visit[i][j]){
				n_dfs(i, j);
				cnt++;
			}
			if(!s_visit[i][j]){
				s_dfs(i, j);
				cnt2++;
			}
		}
	}
	printf("%d %d\n", cnt, cnt2);
}