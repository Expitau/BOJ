#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) scanf("%d", arr+i);
	arr[n] = 2e9;
	int ans = 0;
	while(k){
		int t = lower_bound(arr, arr+n, k) - arr;
		if(arr[t] > k) t--;
		ans += k/arr[t];
		k %= arr[t];
	}
	printf("%d", ans);
	return 0;
}
