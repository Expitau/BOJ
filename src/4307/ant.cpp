#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int l, n, mx=0, mn=0, z;
		scanf("%d %d", &l, &n);
		for(int i=0; i<n; i++){
			 int a;
			 scanf("%d", &a);
			 mx = max(mx, max(a,l-a));
			 mn = max(mn, min(a,l-a));
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}
