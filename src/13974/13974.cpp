/*
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32

*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[5050];
int dp[5050][5050], k_arr[5050][5050];
int sum[5050];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
}


void solve(){
    for(int i=0; i<5050; i++){
        sum[i] = 0;
        for(int j=0; j<5050; j++) dp[i][j] = k_arr[i][j] = 0;
    }

    for(int i=1; i<=n; i++) sum[i] += sum[i-1] + arr[i];
    

    for(int i=1; i+1 <= n; i++){
        dp[i][i+1] = sum[i+1]-sum[i-1];
        k_arr[i][i+1] = i; 
    }
    for(int t=2; t<n; t++){
        for(int i=1, j=t+1; j<=n; i++, j++){
            dp[i][j] = dp[i][i] + dp[i+1][j]; k_arr[i][j] = i;
            for(int k=k_arr[i][j-1]; k<=k_arr[i+1][j]; k++){
                if(dp[i][k] + dp[k+1][j] < dp[i][j]){
                    dp[i][j] =  dp[i][k] + dp[k+1][j];
                    k_arr[i][j] = k;
                }
            }
            dp[i][j] += sum[j] - sum[i-1];
        }
    }

    cout << dp[1][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while(T--) {
        input();solve();
    }

    return 0;
}