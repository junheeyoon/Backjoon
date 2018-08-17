#include <cstdio>
#include <queue>

using namespace std;
queue<int> q;
int F, S, G, U, D;
int ay[2];
int visit[1000001];
int ny;

void bfs(){
	int y;
	while(!q.empty()){
		
		y = q.front();
		q.pop();

		for(int i = 0; i < 2; i++){
			ny = y + ay[i];
			if(ny == G){
				visit[ny] = visit[y] + 1;
				return;
			}
			if(ny > 0 && ny < 1000001){
				if(!visit[ny]){
					visit[ny] = visit[y] + 1;
					q.push(ny);
				}
			}
		}
	}
}
int main(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	
	ay[0] = U;
	ay[1] = -D;

	q.push(S);
	visit[S] = 1;
	if(S == G){
		printf("0\n");
		return 0;
	}
	bfs();
	
	if(visit[G]){
		printf("%d\n", visit[G] - 1);
	}
	else printf("use the stairs\n");
}