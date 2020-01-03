#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[60], b[60], visit[60], vcnt;
vector<int> adj[60], Aans;
bool prime[2010];

int dfs(int now){
	if(visit[now] == vcnt) return 0;
	visit[now] = vcnt;
	for(int it : adj[now]){
		int next = it;
		if(b[next] == 1) continue;
		if(!b[next] || dfs(b[next])){
			b[next] = now;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	
	for(int i=2; i<=2000; i++){
		if(prime[i]) continue;
		for(int j=i*i; j<=2000; j+=i){
			prime[j] = 1;
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			if(!prime[arr[i]+arr[j]]){
				if(arr[i]%2 == arr[1]%2)
					adj[i].push_back(j);
				else
					adj[j].push_back(i);
			}
		}
	}
    
	int mx = 0;
	for(auto it : adj[1]){
		for(int i=0; i<=n; i++) b[i] = 0;
		int ans = 1;
        b[it] = 1;
		for(int j=2; j<=n; j++){
			if(arr[j]%2 == arr[1]%2){
				vcnt++;
				if(dfs(j)){
					ans++;
				}
			}
		}
		if(ans == n/2)
			Aans.push_back(arr[it]);
	}
    sort(Aans.begin(), Aans.end());
    if(Aans.empty()) printf("-1");
    else{
        for(auto it : Aans)
            printf("%d ", it);
    }
	return 0;
}
