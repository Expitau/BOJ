#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100100];
int tree[400400];

void init(int now, int l, int r){
    tree[now] = 1;
    if(l == r) return;
    int m = (l+r)/2;
    init(now*2, l, m);
    init(now*2+1, m+1, r);
}

void update(int now, int l, int r, int pos, int diff){
    if(l > pos || pos > r) return;
    if(l == r){
       tree[now] = diff;
       return;
    }
    int m = (l+r)/2;
    update(now*2, l, m, pos, diff);
    update(now*2+1, m+1, r, pos, diff);
    tree[now] = tree[now*2]*tree[now*2+1];
}

int getAns(int now, int l, int r, int s, int e){
    if(l > e || s > r) return 1;
    if(l <= s && e <= r) return tree[now];
    int m = (l+r)/2;
    return getAns(now*2, l, m, s, e) * getAns(now*2+1, m+1, r, s, e);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++)
            arr[i] = i;
        init(1, 1, n);
        while(k--){
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
            a++; b++;
            if(q == 0){
                swap(arr[a], arr[b]);
                update(1, 1, n, a, arr[a] == a);
                update(1, 1, n, b, arr[b] == b);
            }
            else
                printf("%s\n", getAns(1, 1, n, a, b)?"YES":"NO");
        }
    }
    return 0;
}
