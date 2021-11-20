#include <cstdio>
using namespace std;
using ll = long long;

ll dp[1<<16][200];
ll arr[16], arr2[16];
char str[16][100];

ll gcd(ll a, ll b){
	while(b){
		ll temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main(){
	ll n, k;
	scanf("%lld", &n);
	for(int i=0; i<n; i++)
		scanf("%s", str[i]);
	scanf("%lld", &k);
	
	for(int i=0; i<n; i++){
		arr[i] = 0; 
		arr2[i] = 1;
		for(int j=0; str[i][j]; j++){
			arr[i] = (arr[i]*10 + (str[i][j]-'0'))%k;
			arr2[i] = (arr2[i]*10)%k;
		}
	}
	
	dp[0][0] = 1;
	for(int t=0; t < (1<<n); t++){
		for(int i=0; i<n; i++){
			if(t & (1<<i)) continue;
			for(int j=0; j<k; j++)
				dp[t+(1<<i)][(j*arr2[i] + arr[i])%k] += dp[t][j];
		}
	}
	
	ll fc = dp[(1<<n) - 1][0], fp = 1;
	for(ll i=1; i<=n; i++) fp *= i;
	
	if(fc == 0) fp = 1;
	else{	
		ll g = gcd(fc, fp);
		fc /= g;
		fp /= g;
	}
	
	printf("%lld/%lld\n", fc, fp);
	
	return 0;
}