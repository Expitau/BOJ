#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Query{
public:
    int l, r, idx;
    Query(int _l=0, int _r=0, int _idx=0){
        l = _l;
        r = _r;
        idx = _idx;
    }
};

vector<Query> q;
int arr[100100], Aans[100100], cnt[100100], max_cnt = 0;
int st[100100];

void add(int n){
    st[cnt[n]]--;
    st[++cnt[n]]++;
    if(cnt[n] > max_cnt)
        max_cnt = cnt[n];
}

void del(int n){
    if(--st[cnt[n]] == 0 && cnt[n] == max_cnt)
        max_cnt = cnt[n]-1;
    st[--cnt[n]]++;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        q.push_back({l-1, r-1, i});
    }
    int sz = sqrt(n);
    sort(q.begin(), q.end(), [&](const Query & a, const Query & b)->bool{
         int Aidx = a.l / sz;
         int Bidx = b.l / sz;
         return Aidx == Bidx ? a.r < b.r : Aidx < Bidx;
    });
    int s = 0, e = 0;
    add(arr[0]);
    st[0] = n;
    for(auto it : q){
        int ns = it.l, ne = it.r;
        for(int i=s; i<ns; i++)
            del(arr[i]);
        for(int i=s-1; i>=ns; i--)
            add(arr[i]);
        for(int i=e+1; i<=ne; i++)
            add(arr[i]);
        for(int i=e; i>ne; i--)
            del(arr[i]);
        Aans[it.idx] = max_cnt;
        s = ns; e = ne;
    }
    for(int i=0; i<m; i++) printf("%d\n", Aans[i]);
    return 0;
}
