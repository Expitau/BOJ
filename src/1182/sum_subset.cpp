#include <cstdio>
typedef long long ll;
ll arr[30], n, s, ans;

void dfs(ll now, ll val, ll flag){
	if(flag && val == s) ans++;
	if(now >= n) return;
	dfs(now+1, val+arr[now], 1);
	dfs(now+1, val, 0);
}

int main(){
	scanf("%lld %lld", &n, &s);
	for(int i=0; i<n; i++) scanf("%lld", arr+i);
	dfs(0, 0, 0);
	printf("%lld", ans);
	return 0;
}
