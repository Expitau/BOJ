#include <cstdio>
using namespace std;

int arr[110][110];
long long ans[110][110];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			scanf("%d", arr[i] + j);
	ans[0][0] = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] == 0) continue;
			if(i+arr[i][j] < n) ans[i+arr[i][j]][j] += ans[i][j];
			if(j+arr[i][j] < n) ans[i][j+arr[i][j]] += ans[i][j];
		}
	}
	printf("%lld", ans[n-1][n-1]);
	return 0;
}
