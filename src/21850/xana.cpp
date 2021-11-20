#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree{
private:
  vector<long long> turned, dp[4];
  vector<vector<int>> adj;
  const int INF = 100010;
  int N;

public:
  void input();
  void solve();
  void update_dp(int now, int par, int mod);
  void dfs(int now, int par);
};

void Tree::input(){
  cin >> N;
  adj.resize(N);
  turned.resize(N);
  for(int i=0; i<4; i++) dp[i].resize(N, INF);
  for(int i=1; i<N; i++){
    int a, b;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  for(int i=0; i<N; i++){
    cin >> turned[i];
  }
}

// dp[0] : no touch no turned
// dp[1] : no touch root turned
// dp[2] : touched no turned
// dp[3] : touched root turned

void Tree::update_dp(int now, int par, int mod){
  long long sum = mod;
  vector<long long> arr;

  for(auto next : adj[now]){
    if(next == par) continue;
    sum += dp[mod][next];
    arr.push_back(dp[mod+2][next] - dp[mod][next]);
  }
  
  sort(arr.begin(), arr.end());
  
  for(int i=0; i<=arr.size(); i++){
    if((i+turned[now]+mod)%2 == 1) dp[mod*2+1][now] = min(dp[mod*2+1][now], sum); // default turned on
    else dp[mod*2][now] = min(dp[mod*2][now], sum);
    if(i<arr.size()) sum += arr[i];
  }
}

void Tree::dfs(int now, int par = -1){
  if(par != -1 && adj[now].size() == 1){ // terminal node
    if(turned[now]){
      dp[1][now] = 0;
      dp[2][now] = 1;
    }else{
      dp[0][now] = 0;
      dp[3][now] = 1;
    }
    return;
  }

  for(auto next : adj[now]){
    if(next == par) continue;
    Tree::dfs(next, now);
  }
  
  Tree::update_dp(now, par, 0);
  Tree::update_dp(now, par, 1);
}

void Tree::solve(){
  Tree::dfs(0);
  int ans = min(dp[0][0], dp[2][0]);
  if(ans == INF) cout << "impossible\n";
  else cout << ans << "\n";
}

int main(){
  Tree t;
  t.input();
  t.solve();
  return 0;
}