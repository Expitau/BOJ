#include <iostream>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using ll = long long;
using namespace std;

ll arr[100100];
ll tree[400100];

void init(int now, int l, int r){
  if(l > r) return;
  if(l == r){
    tree[now] = arr[l];
    return;
  }
  init(now*2, l, (l+r)/2); init(now*2+1, (l+r)/2+1, r);
}

void update(int now, int l, int r, int s, int e, int k){
  if(r < s || e < l) return;
  if(s <= l && r <= e){
    tree[now] += k;
    return;
  }
  int m = (l+r)/2;
  update(now*2, l, m, s, e, k);
  update(now*2+1, m+1, r, s, e, k);
}

ll get(int now, int l, int r, int pos){
  if(pos < l || r < pos) return 0;
  if(l == r) return tree[now];

  int m = (l+r)/2;
  return tree[now] + get(now*2, l, m, pos) + get(now*2+1, m+1, r, pos);
}

int n;

void input(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> arr[i];
}

void solve(){
  int q;
  cin >> q;
  while(q--){
    int q, a, b, c;
    cin >> q;
    if(q == 1){
      cin >> a >> b >> c;
      update(1, 1, n, a, b, c);
    }else{
      cin >> a;
      cout << get(1, 1, n, a) << "\n";
    }
  }
}

int main(){
  FASTIO;

  input();
  init(1,1,n);
  solve();

  return 0;
}