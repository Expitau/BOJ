#include <cstdio>

int main(){
	long long n, sx, sy, ax, ay, bx, by, ans = 0;
	scanf("%lld %lld %lld", &n, &sx, &sy);
	ax = sx; ay = sy;
	for(int i=1; i<n; i++){
		scanf("%lld %lld", &bx, &by);
		ans += ax*by - bx*ay;
		ax = bx; ay = by;
	}
	ans += ax*sy - sx*ay;
	if(ans < 0) ans = -ans;
	printf("%lld", ans/2);
	if(ans%2) printf(".5");
	else printf(".0");
	return 0;
}
