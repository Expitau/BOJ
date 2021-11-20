#include <cstdio>
const int mod = 10007;
int arr[100000];

int main(){
	int n;
	scanf("%d", &n);
	arr[0] = 1; arr[1] = 1;
	for(int i=2; i<=n; i++) arr[i] = (arr[i-2] + arr[i-1])%mod;
	printf("%d", arr[n]);
	return 0;
}
