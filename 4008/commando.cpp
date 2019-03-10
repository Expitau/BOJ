#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, a, b, c, d[1000100], s[1000100], stk[1000100], arr[1000100], stktop;
double xpos[1000100];

double cross(int i, int j){
	ll a1 = -2*a*s[i], b1 = a*s[i]*s[i] - b*s[i] + d[i];
	ll a2 = -2*a*s[j], b2 = a*s[j]*s[j] - b*s[j] + d[j];
	return (double)(b1 - b2) / (a2 - a1);
}

int main(){
	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
	for(int i=1; i<=n; i++) scanf("%lld", arr+i), s[i] = s[i-1] + arr[i];
	int pt = 1;
	for(int i=1; i<=n; i++){
		d[i] = a*s[i]*s[i] + b*s[i] + c;
		if(stktop){
			while(pt < stktop && xpos[pt+1] < s[i]) pt++;
			int j = stk[pt];
			d[i] = max(d[i], d[j] + a*(s[i]-s[j])*(s[i]-s[j]) + b*(s[i]-s[j]) + c);
			while(stktop > 1 && xpos[stktop] > cross(stk[stktop], i)) stktop--;
			stk[++stktop] = i;
			xpos[stktop] = cross(stk[stktop-1], i);
			if(pt > stktop) pt = stktop;
		}else{
			stk[++stktop] = i;
			xpos[stktop] = -2e18;
		}
	}
	printf("%lld", d[n]);
	return 0;
}
