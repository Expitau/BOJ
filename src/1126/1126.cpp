#include <iostream>
#include <algorithm>
using namespace std;

int dp[55][500010];

void init(){
    for(int i=0; i<50; i++){
        for(int j=0; j<500010; j++) dp[i][j] = -1;
    }
    dp[0][0] = 0;
}

void update(int & a, int b){
    a = max(a, b);
}

int main(){
    init();

    int n, h;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> h;
        for(int j=0; j<=500000; j++){
            if(dp[i][j] == -1) continue;
            update(dp[i+1][j+h], dp[i][j]);
            if(j > h) update(dp[i+1][j-h], dp[i][j] + h);
            else update(dp[i+1][h-j], dp[i][j] + j);
            update(dp[i+1][j], dp[i][j]);
        }
    }
    cout << ((dp[n][0]) ? dp[n][0] : -1);
}