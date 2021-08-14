#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
using ll = long long;
using lll = __int128;

namespace math{
  ll mul(ll x, ll y, ll mod) { return (lll)x * y % mod; }
  lll mul(ll x, ll y) {return (lll)x*y; }

  ll pow(ll A, ll B, ll MOD){
    ll res = 1;
    A %= MOD;
    while (B > 0) {
    if (B & 1)
        res = mul(res, A, MOD);
    B = B >> 1;
    A = mul(A, A, MOD);
    }
    return res%MOD;
  }
  ll sqrt(ll N){
    ll s = 1, e = N;
    while(s<e){
      lll m = (s+e+1)/2;
      if(m*m <= N){
        s = m;
      }else{
        e = m-1;
      }
    }
    return s;
  }
  ll gcd(ll A, ll B){
    while(B){
      ll T = A;
      A = B;
      B = T%B;
    }
    return A;
  }
}

namespace miller_rabin{
  bool miller_rabin(ll x, ll a) {
  	if (x % a == 0) return 0;
  	ll d = x - 1;
  	while (1) {
  		ll tmp = math::pow(a, d, x);
  		if (d & 1) return (tmp != 1 && tmp != x - 1);
  		else if (tmp == x - 1) return 0;
  		d >>= 1;
  	}
  }
  
  bool isprime(ll x) {
  	for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
  		if (x == i) return 1;
  		if (x > 40 && miller_rabin(x, i)) return 0;
  	}
  	if (x <= 40) return 0;
  	return 1;
  }

}

namespace pollard_rho{
  
  
  void polladRho(ll N, vector<ll> & factor){
    if(N < 2) return;
    if(!(N % 2)){
      factor.push_back(2);
      polladRho(N/2, factor);
      return;
    }
    if(miller_rabin::isprime(N)){
      factor.push_back(N);
      return;
    }
    
    ll x, y, c, d = N;
    auto g = [&](ll X){
      return (c+math::mul(X,X,N))%N;
    };
    do{
      if(d == N){
        x = y = rand() % (N-2) + 2;
        c = rand() % 20 + 1;
        d = 1;
      }
      x = g(x);
      y = g(g(y));
      d = math::gcd(abs(x-y), N);
    }while(d == 1);
    
    polladRho(N/d, factor);
    polladRho(d, factor);
  }
  
  vector<ll> factorize(ll N){
    vector<ll> factor;
    polladRho(N, factor);
    sort(factor.begin(), factor.end());
    return factor;
  }
}



ll solve(ll num){
  // check 1
  ll sq = math::sqrt(num);
  if(sq*sq == num) return 1;
  // check 4
  ll temp = num;
  while(temp && (temp&3) == 0) temp >>= 2;
  if(temp%8 == 7) return 4;
  // check 3
  vector<ll> factor = pollard_rho::factorize(num);
  ll before = 2, cnt = 0;
  for(auto it : factor){
    if(it != before){
      if((before&3) == 3 && (cnt&1) == 1) return 3;
      before = it;
      cnt = 0;
    }
    cnt++;
  }
  if((before&3) == 3 && (cnt&1) == 1) return 3;
  return 2;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll num;
  cin >> num;
  cout << solve(num) << "\n";
  
  return 0;
}