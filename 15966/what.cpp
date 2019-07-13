#include <cstdio>
#include <algorithm>
using namespace std;
int d[1000100];

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		d[a] = max(d[a], d[a-1]+1);
		ans = max(d[a], ans);
	}
	printf("%d", ans);
	return 0;
}
