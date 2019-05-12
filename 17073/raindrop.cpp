#include <cstdio>
using namespace std;
int arr[500100];

int main(){
	int n, k, t=0;
	scanf("%d %d", &n, &k);
	for(int i=1; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a]++; arr[b]++;
	}
	for(int i=2; i<=n; i++) if(arr[i] == 1) t++;
	printf("%.6lf", (double)k/(double)t);
	return 0;
}
