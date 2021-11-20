#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll arr[1001000], tree[4000100];

void init(int now, int l, int r){
    if(l == r){
        tree[now] = arr[l];
        return;
    }
    int m = (l+r)/2;
    init(now*2, l, m);
    init(now*2+1, m+1, r);
    tree[now] = (tree[now*2]*tree[now*2+1])%MOD;
}

void update(int now, int l, int r, int pos, int diff){
    if(pos > r || l > pos) return;
    if(l == r){
        tree[now] = diff;
        return;
    }
    int m = (l+r)/2;
    update(now*2, l, m, pos, diff);
    update(now*2+1, m+1, r, pos, diff);
    tree[now] = (tree[now*2]*tree[now*2+1])%MOD;
}
ll get_Ans(int now, int l, int r, int s, int e){
    if(s > r || l > e) return 1;
    if(s <= l && r <= e) return tree[now];
    int m = (l+r)/2;
    return (get_Ans(now*2, l, m, s, e)*get_Ans(now*2+1, m+1, r, s, e))%MOD;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++) scanf("%lld", arr+i);
    init(1, 1, n);
    for(int i=0; i<m+k; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) update(1, 1, n, b, c);
        else printf("%lld\n", get_Ans(1, 1, n, b, c));
    }
    return 0;
}
