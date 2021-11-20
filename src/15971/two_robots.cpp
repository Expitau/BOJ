#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> adj[100100];
int visit[100100], n, s, e;

int dfs(int now, int sum, int mx){
	visit[now] = 1;
	if(now == e) return sum - mx;
	for(auto it : adj[now]){
		if(visit[it.first]) continue;
		int k = dfs(it.first, sum + it.second, max(mx, it.second));
		if(k != -1) return k;
	}
	return -1;
}

int main(){
	scanf("%d %d %d", &n, &s, &e);
	for(int i=0; i<n-1; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	printf("%d", dfs(s, 0, 0));
	return 0;
}
