#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

class Seg{
public:
    int tree[300000], lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = v;
        while(x > 1){
            x >>= 1;
            tree[x] = max(tree[2*x], tree[2*x+1]);
        }
    }
    int query(int s, int e){
        s += lim;
        e += lim;
        int ret = -1e9;
        while(s < e){
            if(s%2 == 1) ret = max(ret, tree[s++]);
            if(e%2 == 0) ret = max(ret, tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = max(ret, tree[s]);
        return ret;
    }
};

Seg seg;

int n, q;
int dep[100010], par[18][100010], pae[100010], sz[100010];
int comp[100010], head[100010], lab[100010];
int piv1, piv2;
vector<pii> adj[100010];

void dfs(int now, int p){
    sz[now] = 1;
    for(auto next : adj[now]){
        if(next.first == p) continue;
        dep[next.first] = dep[now] + 1;
        par[0][next.first] = now;
        pae[next.first] = next.second;
        dfs(next.first, now);
        sz[now] += sz[next.first];
    }
}

void hld(int now, int p){
    sort(adj[now].begin(), adj[now].end(), [&](const pii & a, const pii & b){
        return sz[a.first] > sz[b.first];
    });
    int fnd = -1;
    for(auto & next : adj[now]){
        if(next.first == p) continue;
        comp[next.first] = comp[now];
        lab[next.first] = ++piv2;
        fnd = next.first;
        hld(next.first, now);
        break;
    }
    for(auto & next : adj[now]){
        if(next.first == p || next.first == fnd) continue;
        comp[next.first] = ++piv1;
        head[piv1] = next.first;
        lab[next.first] = ++piv2;
        hld(next.first, now);
    }
}

int lca(int s, int e){
    if(dep[s] > dep[e]) swap(s, e);
    int dx = dep[e] - dep[s];
    for(int i=0; i<17; i++){
        if((dx >> i) & 1)  e = par[i][e];
    }
    for(int i=16; i>=0; i--){
        if(par[i][s] != par[i][e]){
            s = par[i][s];
            e = par[i][e];
        }
    }
    if(s == e) return s;
    return par[0][s];
}

int query(int s, int e){
    int ret = 0;
    while(comp[s] != comp[e]){
        ret = max(ret, seg.query(lab[head[comp[s]]], lab[s]));
        s = par[0][head[comp[s]]];
    }
    ret = max(ret, seg.query(lab[e]+1, lab[s]));
    return ret;
}

int s[100010], e[100010], x[100010];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d %d %d", s+i, e+i, x+i);
        adj[s[i]].push_back({e[i], x[i]});
        adj[e[i]].push_back({s[i], x[i]});
    }
    dfs(1, 0);
    for(int i=1; i<=16; i++){
        for(int j=1; j<=n; j++){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    head[1] = comp[1] = lab[1] = piv1 = piv2 = 1;
    hld(1, 0);
    seg.init(n);
    for(int i=2; i<=n; i++){
        seg.add(lab[i], pae[i]);
    }
    
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int q, u, v;
        scanf("%d %d %d", &q, &u, &v);
        if(q == 1){
            if(dep[s[u]] > dep[e[u]]) swap(s[u], e[u]);
            seg.add(lab[e[u]], v);
        }else{
            printf("%d\n", max(query(u, lca(u,v)), query(v, lca(u, v))));
        }
    }
    return 0;
}
