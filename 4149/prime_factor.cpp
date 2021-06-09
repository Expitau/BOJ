#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

ll checklist[10] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

ll pow(ll a, ll b, ll n){
	if(b == 0) return 1;
	ll res = pow(a, b/2, n);
	res = (res*res)%n;
	if(b%2) res = (res*a)%n;
	return res;
}

ll gcd(ll a, ll b){
	ll tmp;
	while(b){
		tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}
bool isPrime(ll n){
	ll d, s;
	for(d=n, s=0 ; !(d%2) ; d/=2,s++);
	printf("%lld %lld %lld\n", n, d, s);

	for(int i=0; i<7 && n <= checklist[i]; i++){
		ll a = checklist[i];
		ll temp = pow(a, d, n);

		if(temp == 1) return true;
		for(int i=0; i<s; i++){
			if(temp == n-1) return true;
			temp = (temp*temp)%n;
		}
	}
	return false;
}

vector<long long> ans;

void getFactor(ll n){
	if (n==1) return;
	if(isPrime(n)){
		ans.push_back(n);
		return;
	}

	ll x, y, c, g = n;

	auto f = [=](ll x){
		return ((__int128_t)x*x%n + c) %n;
	};

	do{
		if(g == n){
			x = y = rand()%(n-2);
			c = rand()%10 + 1;
			g = 1;
		}
		x = f(x);
		y = f(f(y));
		g = gcd((abs(x-y)), n);
	}while(g == 1);
	
	getFactor(g);
	getFactor(n / g);
}


int main(){
	ll n;
	scanf("%lld",&n);
	getFactor(n);
	sort(ans.begin(), ans.end());
	for(auto it : ans) printf("%lld\n", it);

	return 0;
}
