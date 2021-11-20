#include <cstdio>
using namespace std;

int par[300];

int getPar(int now){
	if(par[now] == now) return now;
	return par[now] = getPar(par[now]);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) par[i] = i;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int k;
			scanf("%d", &k);
			if(k)
				par[getPar(i)] = getPar(j);
		}
	}
	int a, b, flag = 1; scanf("%d", &a);
	for(int i=1; i<m; i++){
		scanf("%d", &b);
		if(getPar(a) != getPar(b)){
			flag = 0;
			break;
		}
		a = b;
	}
	printf("%s", flag?"YES":"NO");
	return 0;
}
