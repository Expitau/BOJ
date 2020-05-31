#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dep[100100], par[100100], sz[100100];
int comp[100100], head[100100], lab[100100], rlab[100100], piv1, piv2;
vector<int> gph[100100];
set<int> black[100100];

void dfs(int now, int p=0){
    sz[now] = 1;
    dep[now] = dep[p] + 1;
    par[now] = p;
    for(auto next : gph[now]){
        if(next == p) continue;
        dfs(next, now);
        sz[now] += sz[next];
    }
}

void hld(int now, int p=0){
    sort(gph[now].begin(), gph[now].end(), [&](const int & A, const int & B)->bool{
        return sz[A] > sz[B];
    });
    
    for(auto next : gph[now]){
        if(next == p) continue;
        comp[next] = comp[now];
        lab[next] = ++piv2;
        rlab[piv2] = next;
        hld(next, now);
        break;
    }

    for(auto next : gph[now]){
        if(next == p || comp[next] != 0) continue;
        comp[next] = ++piv1;
        head[piv1] = next;
        lab[next] = ++piv2;
        rlab[piv2] = next;
        hld(next, now);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    dfs(1);
    head[1] = comp[1] = rlab[1] = lab[1] = piv1 = piv2 = 1;
    hld(1);
    int T;
    scanf("%d", &T);
    while(T--){
        int q, v;
        scanf("%d %d", &q, &v);
        if(q == 1){
            set<int> & B = black[comp[v]];
            auto it = B.find(lab[v]);
            if(it == B.end())
                B.insert(lab[v]);
            else
                B.erase(it);
        }else{
            int ans = 0;
            while(v){
                set<int> & B = black[comp[v]];
                if(!B.empty() && *(B.begin()) <= lab[v])
                    ans = rlab[*(B.begin())];
                v = par[head[comp[v]]];
            }
            printf("%d\n", ans?ans:-1);
        }
    }
    return 0;
}