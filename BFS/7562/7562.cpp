#include <cstdio>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int arr[101][101];
int visit[101][101];
int N;
int result_x, result_y;
int num;
int x, y;

void calculate(){
	while(!q.empty()){
		printf("2\n");
		for(int i = 0; i < N; i++){
			if(arr[q.front().second][i] && !visit[q.front().first][i]){
				q.push(make_pair(q.front().first, i));
				visit[q.front().first][i] = visit[q.front().first][q.front().second] + 1;
			}
		}
		printf("%d %d\n", q.front().first, q.front().second);
		q.pop();
	}
}

int main(){
	printf("hello");
	scanf("%d %d %d %d", &N, &result_x, &result_y, &num);
	printf("%d", num);
	while(num--){
		scanf("%d %d", &x, &y);
		printf("tt\n");
		arr[x][y] = 1;
		q.push(make_pair(x, y));
	}
	printf("1\n");
	calculate();
	
	printf("%d\n", visit[result_x][result_y]);

}
