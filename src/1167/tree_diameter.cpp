#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[100100];
int visit[100100], vcnt = 1;

pair<int, int> dfs(int n){
    visit[n] = vcnt;
    pair<int, int> ans = {n, 0};
    for(auto i : adj[n]){
        if(visit[i.first] == vcnt) continue;
        auto r = dfs(i.first);
        r.second += i.second;
        if(ans.second <= r.second) ans = r;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int k, a, b;
        scanf("%d", &k);
        while(1){
            scanf("%d", &a);
            if(a == -1) break;
            scanf("%d", &b);
            adj[k].push_back({a, b});
        }
    }
    int k = dfs(1).first; vcnt++;
    printf("%d", dfs(k).second);
    return 0;
}

