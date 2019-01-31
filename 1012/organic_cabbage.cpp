#include <cstdio>
int arr[60][60], visit[60][60], vcnt;
int pos[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

void dfs(int x, int y){
	visit[x][y] = vcnt;
	for(int i=0; i<4; i++){
		int X = x+pos[0][i], Y = y+pos[1][i];
		if(X<0||Y<0||arr[X][Y]==0||visit[X][Y]==vcnt) continue;
		dfs(X,Y);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, k, ans = 0;
		scanf("%d %d %d", &m, &n, &k);
		for(int i=0; i<60; i++) for(int j=0; j<60; j++) arr[i][j] = 0;
		for(int i=0; i<k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			arr[b][a] = 1;
		}
		vcnt++;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				if(arr[i][j] == 0 || visit[i][j] == vcnt) continue;
				ans++;
				dfs(i, j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
