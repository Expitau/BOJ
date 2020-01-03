#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[220];
int b[220], visit[220], vcnt;

int dfs(int now){
	if(visit[now] == vcnt)
		return 0;
	visit[now] = vcnt;
	for(auto it : adj[now]){
		if(b[it] == 0 || dfs(b[it])){
			b[it] = now;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		int k;
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			int temp;
			scanf("%d", &temp);
			adj[i].push_back(temp);
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		vcnt++;
		ans += dfs(i);
	}
	printf("%d", ans);
	return 0;
}

