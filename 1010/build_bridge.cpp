#include <cstdio>
long long d[33][33];

int main(){
	for(int i=0; i<=30; i++) d[i][0] = 1;
	for(int i=1; i<=30; i++)
		for(int j=1; j<=30; j++) d[i][j] = d[i-1][j] + d[i-1][j-1];
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", d[b][a]);
	}
	return 0;
}
