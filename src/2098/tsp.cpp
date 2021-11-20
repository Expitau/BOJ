#include <cstdio>
#include <algorithm>
using namespace std;
int arr[50][50], d[1000000][20];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) scanf("%d", arr[i] + j);
    }
    for(int i=0; i<1<<n; i++) for(int j=0; j<n; j++) d[i][j] = 2e9;
    d[1][0] = 0;
    for(int i=1; i<1<<n; i++){
        for(int j=0; j<n; j++){
            int t = i^(1<<j);
            if((i & (1<<j)) == 0){
                for(int k=0; k<n; k++){
                    if((i & (1<<k)) != 0 && arr[k][j] != 0){
                        d[t][j] = min(d[t][j], d[i][k] + arr[k][j]);
                    }
                }
            }
        }
    }
    int ans = 2e9;
    for(int i=0; i<n; i++){
        if(arr[i][0] != 0) ans = min(ans, d[(1<<n)-1][i] + arr[i][0]);
    }
    printf("%d", ans);
    return 0;
}
