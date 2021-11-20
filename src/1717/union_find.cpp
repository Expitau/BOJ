#include <cstdio>
int prt[1000100];
int findprt(int now){
	if(prt[now] == now) return now;
	return prt[now] = findprt(prt[now]);
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) prt[i] = i;
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a){
			if(findprt(b) == findprt(c)) printf("YES\n");
			else printf("NO\n");
		}else prt[findprt(b)] = findprt(c);
	}
	return 0;
}
