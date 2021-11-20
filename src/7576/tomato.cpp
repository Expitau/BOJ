#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int arr[1010][1010], rk[1010][1010], pos[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
queue<pii> que;

int main(){
	int m, n, cnt = 0, lastrk=0;
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", arr[i]+j);
			if(arr[i][j] == 1) que.push({i, j});
			else if(arr[i][j] == 0) cnt++;
		}
	}
	while(!que.empty()){
		int x = que.front().first, y = que.front().second; que.pop();
		for(int i=0; i<4; i++){
			int X = x+pos[0][i], Y = y+pos[1][i];
			if(X<1||X>n||Y<1||Y>m||arr[X][Y]!=0) continue;
			arr[X][Y] = 1; rk[X][Y] = rk[x][y]+1;
			que.push({X, Y});
            lastrk = max(lastrk, rk[X][Y]);
            cnt--;
        }
	}
	if(cnt == 0) printf("%d", lastrk);
    else printf("-1");
    return 0;
}
