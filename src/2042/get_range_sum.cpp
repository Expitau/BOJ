#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

ll arr[1000100], tree[4000100];

void update(int now, int s, int e, int t, ll v){
	if(s > t || t > e) return;
	if(s == e){
		tree[now] = v;
		return;
	}
	update(now*2, s, (s+e)/2, t, v);
	update(now*2+1, (s+e)/2+1, e, t, v);
	tree[now] = tree[now*2] + tree[now*2+1];
}

ll getSum(int now, int s, int e, int l, int r){
	if(s > r || e < l) return 0LL;
	if(l <= s && e <= r) return tree[now];
	return getSum(now*2, s, (s+e)/2, l, r)+getSum(now*2+1, (s+e)/2+1, e, l, r);
}	

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++) {
		scanf("%lld", arr+i);
		update(1, 1, n, i, arr[i]);
	}
	for(int i=0; i<m+k; i++){
		ll m, a, b;
		scanf("%lld %lld %lld", &m, &a, &b);
		if(m == 1) update(1, 1, n, a, b);
		else printf("%lld\n", getSum(1, 1, n, a, b));
	}
	return 0;
}
