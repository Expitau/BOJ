#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[1010];
int visit[1010];
void dfs(int now){
	visit[now] = 1;
	for(auto it : adj[now]){
		if(!visit[it]) dfs(it);
	}
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(visit[i]) continue;
		ans++;
		dfs(i);
	}
	printf("%d", ans);
	return 0;
}
