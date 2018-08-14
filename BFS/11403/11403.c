#include <stdio.h>
int visit[101];
int arr[101][101];
int N;
void go(int x){
	visit[x] = 1;
	for(int i = 1; i <= N; i++){
		if(!visit[i] && arr[x][i]){	
			go(i);
		}
	}
}
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				if(!visit[k] && arr[i][k]){			
					go(k);
				}
			}
			arr[i][j] = visit[j];
		}
		for(int m = 1; m <= N; m++){
			visit[m] = 0;
		}		
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}