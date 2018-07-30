#include <stdio.h>
typedef struct Targetpoint{
	int x;
	int y;
}Point;
Point queue[10001];
int map[101][101];
int front = 0;
int last = 0;

int row, col;
int bfs(){
	Point current;
	Point next;
	current.x = 1;
	current.y = 1;
	int dx[4] = { -1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	queue[front++] = current;
	while(front > last){
		current = queue[last++];	
		if(current.x > 0 && current.x <= col && current.y > 0 && current.y <= row){
			for(int i = 0; i < 4; i++){
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];
				
				if(map[next.y][next.x] == 1){
					map[next.y][next.x] = map[current.y][current.x] + 1;
					queue[front++] = next;
				}
			}
		}
	}
	return map[row][col];
}
int main(void) {
	scanf("%d %d", &row, &col);
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <=col; j++)
			scanf("%1d", &map[i][j]);
	}
	printf("%d", bfs());
	return 0;
}
