#include <cstdio>
using namespace std;

int par[100100];

int getPar(int n){
	if(par[n] == n) return n;
	return par[n] = getPar(par[n]);
}

int main(){
	int g, p;
	scanf("%d %d", &g, &p);
	for(int i=1; i<=g; i++) par[i] = i;
	int ans = 0;
	for(int i=0; i<p; i++){
		int a;
		scanf("%d", &a);
		int k = getPar(a);
		if(k > 0){
			par[k] = getPar(k-1);
			ans++;
		}else break;
	}
	printf("%d", ans);
	return 0;
}
