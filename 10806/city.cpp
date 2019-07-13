#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int v, e, vcnt;
int visit[100100], G[100100];
vector<int> adj[100100], adj2[100100], ans;

int getpar(int now){
    if(G[now] == now) return now;
    return G[now] = getpar(G[now]);
}

int dfs(int now, int par){
    visit[now] = ++vcnt;
    int be = visit[now];
    for(auto next : adj[now]){
        if(next == par) continue;
        if(visit[next]) be = min(be, visit[next]);
        else{
            int rv = dfs(next, now);
            if(rv <= visit[now])
                G[getpar(next)] = getpar(now);
            be = min(be, rv);
        }
    }
    return be;
}

void dfs2(int now){
    visit[now] = vcnt;
    for(auto next : adj[now]){
        if(G[next] != G[now]){
            adj2[G[now]].push_back(G[next]);
            adj2[G[next]].push_back(G[now]);
        }if(visit[next] != vcnt)
            dfs2(next);
    }
}

void dfs3(int now, int par = 0){
	if(adj2[now].size() == 1)
		ans.push_back(now);
	for(auto it : adj2[now])
		if(it != par) 
			dfs3(it, now);
}

int main(){
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=v; i++) G[i] = i;
    for(int i=1; i<=v; i++){
        sort(adj[i].begin(), adj[i].end());
        auto temp = unique(adj[i].begin(), adj[i].end());
        for(auto it = temp; it != adj[i].end(); it++)
            G[getpar(*it)] = getpar(i);
        adj[i].erase(temp, adj[i].end());
    }
    dfs(1, 0);
    vector<int> Gnum;
    for(int i=1; i<=v; i++){
        getpar(i);
        Gnum.push_back(G[i]);
    }
    sort(Gnum.begin(), Gnum.end());
    Gnum.erase(unique(Gnum.begin(), Gnum.end()), Gnum.end());
    vcnt++;
    dfs2(1);
    int k = Gnum[0];
    for(auto it: Gnum){
        sort(adj2[it].begin(), adj2[it].end());
        adj2[it].erase(unique(adj2[it].begin(), adj2[it].end()), adj2[it].end());
        if(adj2[it].size() > adj2[k].size()) k = it;
    }
   	dfs3(k);
	if(ans.size()%2) ans.push_back(k);
    printf("%d\n", ans.size()/2);
	for(int i=0; i*2 < ans.size(); i++)
		printf("%d %d\n", ans[i], ans[i+ans.size()/2]);
	return 0;
}
