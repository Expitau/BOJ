#include <cstdio>
#include <cmath>

const long long mod = 9901;
long long d[300][1<<15];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    d[0][0] = 1;
    int mj = (1<<(m+1)) - 1;
    for(int i=0; i<=n*m; i++){
        for(int j=0; j<=mj; j++){
            if(d[i][j]){
                int k = j>>1;
                if(k%2 == 1) d[i+1][k] = (d[i+1][k]+d[i][j])%mod;
                else{
                    d[i+1][k+1+(1<<m)] = (d[i+1][k+1+(1<<m)]+d[i][j])%mod;
                    if(i%m != m-1 && (k>>1)%2 != 1) d[i+1][k+3] = (d[i][j]+d[i+1][k+3])%mod;
                }
            }
        }
    }
    printf("%lld", d[n*m][1]);
    return 0;
}
