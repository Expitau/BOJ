#include <cstdio>
using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int k = gcd(n, m);
	printf("%d\n%d", k, (n/k)*m);
	return 0;
}
