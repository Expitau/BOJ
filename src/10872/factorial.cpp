#include <cstdio>
typedef long long ll;
int main(){
	ll n, ans=1;
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) ans *= i;
	printf("%lld", ans);
	return 0;
}
