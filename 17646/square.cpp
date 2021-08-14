/*
ref : http://www.secmem.org/authors/ho94949/
*/

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
  lll abs(lll p){
    if(p < 0) return -p;
    return p;
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

namespace squres{
  class GaussianInt{
  public:
    GaussianInt(lll R = 0, lll I = 0){re=R; im=I;}
    lll re, im;
    lll norm(){
      return (this->re)*(this->re) + (this->im)*(this->im);
    }
    GaussianInt operator /(const GaussianInt & z)const{
      lll t0 = this->re, t1 = this->im;
      lll z0 = z.re, z1 = z.im;
      lll N = z.re*z.re + z.im*z.im;
      auto rem = [&](lll a, lll b){
        lll ret = a%b;
        if(ret < 0) ret += b;
        if(2*ret > b) ret -= b;
        return ret;
      };
      auto quo = [&](lll a, lll b){return (a-rem(a,b))/b;};
      return GaussianInt(quo(t0*z0+t1*z1, N), quo(t1*z0-t0*z1, N));
    }

    GaussianInt operator %(const GaussianInt & z)const{
      lll t0 = this->re, t1 = this->im;
      lll z0 = z.re, z1 = z.im;
      GaussianInt q = (*this)/z;
      lll q0 = q.re, q1 = q.im;
      return GaussianInt(t0-q0*z0+q1*z1, t1-q0*z1-q1*z0);
    }

    static GaussianInt gcd(GaussianInt A, GaussianInt B){
      while(B.re != 0 || B.im != 0){
        GaussianInt temp = A;
        A = B;
        B = temp%B;
      }
      return A;
    }
  };

  lll quadratic_residue(lll p){
    lll k = p/4, j = 2;
    while(true){
      lll a = math::pow(j, k, p);
      lll b = (a*a)%p;
      if(b == p-1) return a;
      j++;
    }
  }

  pair<ll, ll> two_squres_prime(ll p){
    if(p == 2) return {1,1};
    lll a = quadratic_residue(p);
    GaussianInt g = GaussianInt::gcd(GaussianInt(p,0), GaussianInt(a,1));
    return {math::abs(g.re), math::abs(g.im)};
  }

  pair<ll, ll> two_squres(ll N){
    ll squre = 1, before = 0;
    vector<ll> primes;
    for(auto it : pollard_rho::factorize(N)){
      if(before == it){
        squre *= it;
        before = 0;
      }else{
        if(before) primes.push_back(before);
        before = it;
      }
    }
    if(before) primes.push_back(before);

    if(primes.size() == 0) return {squre, 0};
    for(auto it : primes){
      if(it % 4 == 3) return {-1, -1};
    }
    pair<ll, ll> R = {squre, 0};
    for(auto it : primes){
      pair<ll, ll> T = two_squres_prime(it);
      R = {R.first*T.first+R.second*T.second, R.first*T.second-R.second*T.first};
    }
    return {math::abs(R.first), math::abs(R.second)};
  }

  vector<ll> get_squres(ll N){
    vector<ll> res;
    if(N == 0) return res;
    if(N%4 == 0){
      int cnt = 0;
      while(N%4 == 0){
        N /= 4;
        cnt++;
      }
      res = get_squres(N);
      for(auto & it : res) it <<= cnt;
      return res;
    }

    if(N%8 == 7){
      res = get_squres(N-1);
      res.push_back(1);
      return res;
    }
    pair<ll, ll> ab = two_squres(N);
    if(ab.first != -1 && ab.second != -1){
      if(ab.first != 0) res.push_back(ab.first);
      if(ab.second != 0) res.push_back(ab.second);
      return res;
    }

    int i = 2;
    if(N%4 == 3) i = 1;
    while(true){
      pair<ll, ll> ab = two_squres(N-i*i);
      if(ab.first != -1 && ab.second != -1){
        if(ab.first) res.push_back(ab.first);
        if(ab.second) res.push_back(ab.second);
        res.push_back(i);
        return res;
      }
      i+=2;
    }
  }

  void solve(ll num){
    vector<ll> res = get_squres(num);
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(auto it : res) cout << it << " ";
    cout << "\n";
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll num;
  cin >> num;
  squres::solve(num);

  return 0;
}