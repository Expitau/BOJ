#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[2001000], str2[4001000];
int d[4001000];

int main(){
    scanf("%s", str);
    int n = strlen(str);
    for(int i=0; i<n; i++){
        str2[i*2] = str[i];
        str2[i*2+1] = '#';
    }
    int p = -1, l = -1;
    long long ans = 0;
    for(int i=0; i<n*2; i++){
        if(l >= i)
            d[i] = min(d[2*p-i], l-i);
        while(i-d[i]-1>=0 && i+d[i]+1 < 2*n && str2[i-d[i]-1]==str2[i+d[i]+1])
            d[i]++;
        if(d[i]+i > l){
            l = d[i]+i;
            p = i;
        }
        if(i%2) ans += (d[i]+1)/2;
        else ans += 1 + d[i]/2;
    }
    printf("%lld", ans);
    return 0;
}

