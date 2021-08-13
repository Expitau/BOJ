#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

using ll = long long;



namespace miller_rabin{
  ll mul(ll x, ll y, ll mod) { return (__int128)x * y % mod; }
  
  ll _pow(ll A, ll B, ll MOD){
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
  
  bool miller_rabin(ll x, ll a) {
  	if (x % a == 0) return 0;
  	ll d = x - 1;
  	while (1) {
  		ll tmp = _pow(a, d, x);
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
  ll gcd(ll A, ll B){
    while(B){
      ll T = A;
      A = B;
      B = T%B;
    }
    return A;
  }
  
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
      return (c+miller_rabin::mul(X,X,N))%N;
    };
    do{
      if(d == N){
        x = y = rand() % (N-2) + 2;
        c = rand() % 20 + 1;
        d = 1;
      }
      x = g(x);
      y = g(g(y));
      d = gcd(abs(x-y), N);
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

namespace euler_phi{
  ll phi(ll num){
    vector<ll> factor = pollard_rho::factorize(num);
    ll res = 1, now = 2, mul = 1;
    for(auto it : factor){
      if(it != now){
        res *= mul-(mul/now);
        now = it;
        mul = 1;
      }
      mul *= it;
    }
    res *= mul-(mul/now);
    return res;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll num;
  cin >> num;
  cout << euler_phi::phi(num) << "\n";
  
  return 0;
}