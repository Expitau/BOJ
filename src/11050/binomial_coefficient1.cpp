#include <cstdio>
typedef long long ll;
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	long long ans = 1;
	for(int i=1; i<=n; i++) ans *= i;
	for(int i=1; i<=k; i++) ans /= i;
	for(int i=1; i<=n-k; i++) ans /= i;
	printf("%lld", ans);
	return 0;
}
