#include <iostream>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int n;
int arr[100100];
int tree[20][100100];

void input(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> arr[i];
}

void merge(int l, int r, int depth){
  int m = (l+r)/2;
  int i = l, j = m+1, k = l;
  while(i <= m && j <= r){
    if(tree[depth+1][i] < tree[depth+1][j]){
      tree[depth][k++] = tree[depth+1][i++];
    }else{
      tree[depth][k++] = tree[depth+1][j++];
    }
  }
  while(i <= m){
    tree[depth][k++] = tree[depth+1][i++];
  }
  while(j <= r){
    tree[depth][k++] = tree[depth+1][j++];
  }
}

void make_tree(int l, int r, int depth){
  if(l == r){
    tree[depth][l] = arr[l];
    return;
  }
  int m = (l+r)/2;
  make_tree(l, m, depth+1); make_tree(m+1, r, depth+1);
  merge(l, r, depth);
}

int get_more_than_k(int k, int l, int r, int depth){
  int res = upper_bound(tree[depth]+l, tree[depth]+r+1, k)-(tree[depth]+l);
  return (r-l+1) - res;
}

int query(int k, int s, int e, int l, int r, int depth){
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) {
    return get_more_than_k(k, s, e, depth);
  }
  int m = (s+e)/2;
  return query(k, s, m, l, r, depth+1) + query(k, m+1, e, l, r, depth+1);
}

void solve(){
  int q, i, j, k;
  cin >> q;
  while(q--){
    cin >> i >> j >> k;
    cout << query(k, 1, n, i, j, 0) << "\n";
  }
}

int main(){
  FASTIO;
  input();
  make_tree(1, n, 0);
  solve();

  return 0;
}