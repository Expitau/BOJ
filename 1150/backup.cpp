#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class Data{
public:
  ll l, r, val;
  Data(ll V=0, ll L=0, ll R=0){
    l = L; r = R; val = V;
  }
  bool operator < (const Data & D)const{
    return val > D.val;
  }
};

priority_queue<Data> pq;
Data point[100100];

int main(){
  ll N, K, pos;
  cin >> N >> K >> pos;
  for(int i=1; i<N; i++){
    ll npos;
    cin >> npos;
    point[i] = {npos-pos, i-1, i+1};
    pq.push({npos-pos, i, i+1});
    pos = npos;
  }
  point[N] = {0, N-1, N+1};

  ll ans = 0, cnt = 0;
  while(cnt < K){
    const auto now = pq.top(); pq.pop();
    if(now.l >= 1 && now.r <= N && now.r == point[now.l].r && now.l == point[now.r].l){
        ans += now.val; cnt++;
        Data next;
        next.l = point[now.l].l;
        next.r = point[now.r].r;
        next.val = point[next.l].val + point[now.r].val - now.val;
        point[next.l].val = next.val;
        point[next.l].r = next.r;
        point[next.r].l = next.l;

        pq.push(next);
    }
  }
  cout << ans << "\n";
  return 0;
}