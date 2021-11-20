/**
 LCA with spars table 
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<pii> gph[100100]; 
int par[17][100100], dep[100100], n; 
ll cost[100100]; 

void dfs(int now, int p = 0){
    dep[now] = dep[p] + 1;
    par[0][now] = p;
    for(auto it : gph[now]){
        int next = it.first, w = it.second;
        if(next == p) continue;
        cost[next] = cost[now] + w;
        dfs(next, now);
    }
}

int lca(int s, int e){
    if(dep[s] > dep[e])  swap(s, e);
    int dx = dep[e] - dep[s];
    for(int i=0; i<17; i++)
        if((dx >> i) & 1) e = par[i][e];
    for(int i=16; i>=0; i--){
        if(par[i][s] != par[i][e]){
            s = par[i][s];
            e = par[i][e];
        }
    }
    if(s == e) return s;
    return par[0][s]; 
}

void fill_par(){
    for(int i=1; i<=16; i++)
        for(int j=1; j<=n; j++)
            par[i][j] = par[i-1][par[i-1][j]];
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gph[u].push_back({v, w});
        gph[v].push_back({u, w});
    }
    dfs(1);
    fill_par();
    int T;
    scanf("%d", &T);
    while(T--){
        int q, u, v, l;
        scanf("%d %d %d", &q, &u, &v);
        long long ans = 0;

        l = lca(u, v);
        if(q == 1){
            ans = cost[u] + cost[v] - 2*cost[l];
        }else{
            int k;
            scanf("%d", &k);
            
            k--;
            if(k > dep[u] - dep[l]){
                k = dep[u] + dep[v] - dep[l]*2 - k;
                ans = v;
            }else
                ans = u;
            // u ~ l k번째
            for(int i=0; i<17; i++)
                if((k >> i) & 1) ans = par[i][ans];
        }
        printf("%lld\n", ans);
    }
    return 0;
}