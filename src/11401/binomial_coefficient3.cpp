#include <cstdio>
typedef long long ll;
const ll mod = 1000000007;
ll inv[5000000];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	inv[1] = 1;
	for(int i=2; i<=n; i++) inv[i] = (mod - ((mod/i)*inv[mod%i])%mod)%mod;
	ll ans = 1;
	for(ll i=1; i<=n; i++) ans = (ans*i)%mod;
	for(ll i=1; i<=k; i++) ans = (ans*inv[i])%mod;
	for(ll i=1; i<=n-k; i++) ans = (ans*inv[i])%mod;
	printf("%lld", ans);
	return 0;
}
