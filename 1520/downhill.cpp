#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int arr[550][550], d[550][550];
auto cmp=[&](pii A, pii B){return arr[A.first][A.second]<arr[B.first][B.second];};
priority_queue<pii,vector<pii>, decltype(cmp)> que(cmp);
int pos[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", arr[i]+j);
	que.push({1, 1});
	d[1][1] = 1;
	while(!que.empty()){
		int nowx = que.top().first, nowy = que.top().second; que.pop();
		for(int i=0; i<4; i++){
			int X = nowx+pos[0][i], Y = nowy+pos[1][i];
			if(X<1||X>n||Y<1||Y>m||arr[X][Y]>=arr[nowx][nowy]) continue;
			if(d[X][Y] == 0) que.push({X, Y});
			d[X][Y] += d[nowx][nowy];
		}
	}
	printf("%d", d[n][m]); 
	return 0;
}
