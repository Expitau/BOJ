#include <cstdio>
#include <algorithm>
using namespace std;

int last[20];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int k, temp;
        scanf("%d %d", &k, &temp);
        if(last[k] && last[k] != temp+1) ans++;
        last[k] = temp + 1;
    }
    printf("%d", ans);
    return 0;
}
