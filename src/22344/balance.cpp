#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

vector<pii> adj[100100];
ll val[100100], sgn[100100], tot[100100];
pii X = {0,0};

int dfs(ll now){
  for(auto it : adj[now]){
    ll next = it.first, w = it.second;
    if(sgn[next]){
      if(sgn[next] == -sgn[now]){
        if(val[next] + val[now] != w) return 0;
      }else{
        ll newx = -(sgn[next]*val[next] - sgn[now]*(w-val[now]));
        if(newx%2) return 0;
        newx /= 2;
        if(X.second){
          if(X.first != newx) return 0;
        }else X = {newx, 1};
      }
    }else{
      val[next] = w - val[now];
      sgn[next] = -sgn[now];
      if(!dfs(next)) return 0;
    }
  }
  return 1;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  
  val[1] = 0;
  sgn[1] = 1;
  if(dfs(1)){
    if(!X.second){
      for(int i=1; i<=n; i++) tot[i] = -sgn[i]*val[i];
      sort(tot+1, tot+n+1);
      X = {tot[n/2+1], 1};
    }
    
    cout << "Yes\n";
    for(int i=1; i<=n; i++){
      cout << sgn[i]*X.first + val[i] <<" ";
    }
    cout << "\n";
  }else{
    cout << "No\n";
  }
  
  return 0;  
}
