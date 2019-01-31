#include <cstdio>
using namespace std;
const int mod = 10007;
int d[1010];
int main(){
	int n;
	scanf("%d", &n);
	d[0] = d[1] = 1;
    for(int i=2; i<=n; i++) d[i] = (d[i-2]*2 + d[i-1])%mod;
	printf("%d", d[n]);
	return 0;
}
