#include <cstdio>
#include <algorithm>
using namespace std;

int arr[2002000];
int d[2002000];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		arr[i*2-1] = -1;
		scanf("%d", arr+i*2);
	}
    
	int p = 0, r = 0;
	for(int i=1; i<=2*n; i++){
		if(i <= r) d[i] = min(r-i, d[2*p-i]);
		while(i+d[i]+1 <= 2*n && i-d[i]-1 > 0 && arr[i-d[i]-1] == arr[i+d[i]+1]) d[i]++;
		if(i+d[i] > r){
			p = i;
			r = i+d[i];
		}
	}

	int m;
	scanf("%d", &m);
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", d[a+b] >= b-a);
	}
	return 0;
}
