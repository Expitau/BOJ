#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[2010];
int b[2010], visit[2010], vcnt;

int dfs(int now){
	if(visit[now] == vcnt) return 0;
	visit[now] = vcnt;

	for(auto it : adj[now]){
		if(!b[it] || dfs(b[it])){
			b[it] = now;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d", &t);
		while(t--){
			int temp;
			scanf("%d", &temp);
			adj[i].push_back(temp);
			adj[i+n].push_back(temp);
		}
	}

	int ans = 0, ans2 = 0;
	for(int i=1; i<=n; i++){
		vcnt++;;
		if(dfs(i)) ans++;
	}
	
	for(int i=n+1; i<=n*2; i++){
		vcnt++;
		if(dfs(i)){
			ans2++;
			if(ans2 == k) break;
		}
	}

	printf("%d", ans+ans2);

	return 0;
}
