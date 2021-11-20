#include <cstdio>
#include <algorithm>
using namespace std;
int arr[550][550];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			scanf("%d", arr[i]+j);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
	int ans = 0;
	for(int i=1; i<=n; i++) ans = max(arr[n][i], ans);
	printf("%d", ans); 	
	return 0;
}

