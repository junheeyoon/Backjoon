#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int> > q;
int arr[101][101];
int visit[101][101];
int land[101][101];
int len[101][101];
int N;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
int nx, ny;
int cnt;
int curX, curY;
int nextX, nextY;
int dist;
int mindist = 999999;

void land_mark(int x, int y){
	if(x < 0 || y < 0 || x >= N || y >= N)
		return;
	land[x][y] = cnt;

	for(int i = 0; i < 4; i++){
		
		nx = x + ax[i];
		ny = y + ay[i];

		if(!visit[nx][ny] && arr[nx][ny]){
			visit[nx][ny] = 1;
			land_mark(nx, ny);
		}
	}
}

int ABS(int value)
{
    return (value < 0) ? -value : value;
}

void distance(){
	
	for(int i = 0; i < q.size(); i++){
		curX = q[i].first;
		curY = q[i].second;
		for(int j = 0; j < q.size(); j++){
			nextX = q[j].first;
			nextY = q[j].second;

			if(land[curX][curY] != land[nextX][nextY]){
				dist = ABS(nextX - curX) + ABS(nextY - curY) - 1;
				if(mindist > dist){
					mindist = dist;
				}
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j]){
				q.push_back(make_pair(i, j));
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(arr[i][j] && !visit[i][j]){
				cnt++;
				visit[i][j] = 1;
				land_mark(i, j);				
			}
		}
	}
	distance();
	printf("%d\n", mindist);

}