#include <cstdio>
using namespace std;

using ll = long long;

inline ll pow(int n, int k){
    ll ans = 1;
    while(k--) ans *= n;
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<10; i++){
        int after = n, before = 0, pos=0;
        ll ans = 0;
        while(after){
            int k = after/10;
            if(i == 0 && k == 0) break;
            if(i == 0) k--;

            if(after%10 < i){
                ans += (k)*pow(10, pos);
            }else if(after%10 == i){
                ans += (k)*pow(10, pos) + before + 1;
            }else{
                ans += (k+1)*pow(10,pos);
            }

            before += (after%10) * pow(10, pos);
            after /= 10;
            pos++;
        }
        printf("%lld ", ans);
    }

    return 0;
}