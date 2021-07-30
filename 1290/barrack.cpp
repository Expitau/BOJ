#include <iostream>
using namespace std;

const int INF = 1000000;

int calc(int T, int N, int B, int U){
  int b = B, n = N, m = 0, rounds = 0;

  while (b >= T){
    if (m >= n) return INF;
    b -= n - m;
    m = 0;
    if (b > 0) m += U;
    rounds++;
  }

  while (b > 0){
    if (n <= 0) return INF;
    if (b >= n) b -= n;
    else{
      m -= n - b;
      b = 0;
    }
    n -= m;
    if (b > 0) m += U;
    rounds++;
  }

  while (m > 0){
    if (n <= 0) return INF;
    m -= n;
    if (m > 0) n -= m;
    rounds++;
  }

  return rounds;
}
 
int main(){
  int N, B, U;
  cin >> N >> B >> U;

  int res = INF;
  for(int i=0; i<=B; i++)
    res = min(res, calc(i, N, B, U));
  cout << (res == INF ? -1 : res) << "\n";

  return 0;
}