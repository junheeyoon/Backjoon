#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int arr[101][101];
int visit[101];
int height[101];
int N;
int result_x, result_y;
int num;
int x, y;

void calculate(){

	while(!q.empty()){
		int val = q.front();
		q.pop();
		
		for(int i = 1; i <= N; i++){
			if(arr[val][i] == 1 && !visit[i]){
				visit[val] = 1;
				q.push(i);
				height[i] = height[val] + 1;
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d", &N, &result_x, &result_y, &num);
	
	while(num--){
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
		q.push(result_x);
	}
	calculate();
	
	if(height[result_y] == 0){
		printf("-1\n");
	}
	else printf("%d\n", height[result_y]);

}
