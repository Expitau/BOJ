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
    return val < D.val;
  }
};

priority_queue<Data> pq;
Data point[200100];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll N;
  cin >> N;
  N++;
  for(int i=1; i<N; i++){
    ll A;
    cin >> A;
    point[i] = {A, i-1, i+1};
    pq.push({A, i, i+1});
  }
  point[N] = {0, N-1, N+1};

  ll ans = 0, cnt = 0;
  while(cnt < N/2){
    const auto now = pq.top(); pq.pop();
    if(now.l >= 1 && now.r <= N && now.r == point[now.l].r && now.l == point[now.r].l){
        ans += now.val; cnt++;
        cout << ans << "\n";
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
  return 0;
}