#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans, arr[1000100], n, m;

void para(ll l, ll r){
	if(l > r) return;
	ll mid = (l+r)/2, sum = 0;
	for(int i=0; i<n; i++) if(mid < arr[i]) sum += arr[i]-mid;
	if(sum >= m){
		ans = max(ans, mid);
		para(mid+1, r);
	}else para(l, mid-1);
}
int main(){
	ll mx=0;
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%lld", arr+i);
		mx = max(mx, arr[i]);
	}
	para(0, mx);
	printf("%lld", ans);
	return 0;
}
