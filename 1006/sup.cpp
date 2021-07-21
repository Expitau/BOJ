#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n, w;
int arr[2][10010];
int dp[4][10010];


void input(){
	scanf("%d %d", &n, &w);
	for(int i=1; i<=n; i++){
		scanf("%d", arr[0]+i);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", arr[1]+i);
	}
}

void fill_dp(){
	for(int i=2; i<=n; i++){
		dp[0][i] = dp[3][i-1];
		dp[1][i] = dp[3][i-1] + 1;
		dp[2][i] = dp[3][i-1] + 1;
		dp[3][i] = dp[3][i-1] + (arr[0][i] + arr[1][i] <= w ? 1 : 2);
		
		int k = arr[0][i] + arr[0][i-1] <= w;
		int t = arr[1][i] + arr[1][i-1] <= w;
		if(k){
			dp[1][i] = min(dp[1][i], dp[2][i-1] + 1);
			dp[3][i] = min(dp[3][i], dp[2][i-1] + 2);
		}
		if(t){
			dp[2][i] = min(dp[2][i], dp[1][i-1] + 1);
			dp[3][i] = min(dp[3][i], dp[1][i-1] + 2);
		}
		if(k && t){
			dp[3][i] = min(dp[3][i], dp[0][i-1] + 2); 
		}	
	}
}

int solve(){
	int ans = 2*n;
	dp[0][1] = 0, dp[1][1] = 1, dp[2][1] = 1, dp[3][1] = (arr[0][1] + arr[1][1] <= w ? 1 : 2);
	fill_dp();
	ans = min(ans, dp[3][n]);
	int k = arr[0][1] + arr[0][n] <= w, t = arr[1][1] + arr[1][n] <= w;
	if(k){
		dp[0][1] = 2*n, dp[1][1] = 0, dp[2][1] = 2*n, dp[3][1] = 1;
		fill_dp();
		ans = min(ans, dp[2][n]+1);
	}
	if(t){
		dp[0][1] = 2*n, dp[1][1] = 2*n, dp[2][1] = 0, dp[3][1] = 1;
		fill_dp();
		ans = min(ans, dp[1][n]+1);
	}
	if(k && t){
		dp[0][1] = 2*n, dp[1][1] = 2*n, dp[2][1] = 2*n, dp[3][1] = 0;
		fill_dp();
		ans = min(ans, dp[0][n]+2);
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		input();
		int ans = solve();	
		printf("%d\n", ans);
	}
	return 0;
}