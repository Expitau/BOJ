#include <cstdio>
#include <algorithm>
using namespace std;
long long arr[101000];
int main(){
	long long n;
	scanf("%lld", &n);
	for(int i=0; i<n; i++) scanf("%lld", arr+i);
	sort(arr, arr+n, [](long long A, long long B)->bool{return A>B;});
	long long ans = 0;
	for(int i=0; i<n; i++) ans = max(ans, arr[i]*(i+1));
	printf("%lld", ans);
	return 0;
}
