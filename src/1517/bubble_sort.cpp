#include <cstdio>
#include <algorithm>
using namespace std;
long long ans;
int arr[500500], temp[500500];

void mergeSort(int s, int e){
	if(s == e) return;
	int m = (s+e)/2;
	mergeSort(s, m); mergeSort(m+1, e);
	int a = s, b = m+1, c = s;
	while(a <= m && b <= e){
		if(arr[a] <= arr[b]) temp[c++] = arr[a++];
		else{
			temp[c++] = arr[b++];
			ans += m+1-a;
		}
	}
	while(a <= m) temp[c++] = arr[a++];
	while(b <= e) temp[c++] = arr[b++];
	for(int i=s; i<=e; i++) arr[i] = temp[i];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	mergeSort(1, n);
	printf("%lld", ans);
	return 0;
}
