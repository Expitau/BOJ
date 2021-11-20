#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[2020], d[2020][2020];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", arr+i);
    long long ans = 0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(!(k%2)){
                if(k){
                    if(d[i][k-1])
                        d[i][k] = max(d[i][k-1] + arr[(i+k)%n], d[i][k]);
                    if(d[(i+1)%n][k-1])
                        d[i][k] = max(d[(i+1)%n][k-1] + arr[i], d[i][k]);
                }else d[i][k] = arr[i];
            }else{
                if(arr[(n+i-1)%n] < arr[(i+k)%n])
                    d[i][k] = max(d[i][k-1], d[i][k]);
                if(arr[i] > arr[(i+k+1)%n])
                    d[i][k] = max(d[(i+1)%n][k-1], d[i][k]);
            }
            ans = max(ans, d[i][k]);
        }
    }
    printf("%lld", ans);
    return 0;
}
