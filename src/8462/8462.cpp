#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

class Query{
public:
    int s, e, idx;
    Query(){}
    Query(int S, int E, int I){
        s=S; e=E; idx=I;
    }
    bool operator<(const Query & q)const{
        if(s/300 != q.s/300) return s < q.s;
        return e < q.e;
    }
};

int n, m;
int arr[100100];
Query q[100100];
ll k[1000100];
ll ans[100100];
ll power;

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=0; i<m; i++){
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }
    sort(q, q+m);
}

void pop_val(ll s){
    power -= 2*k[s]*s - s;
    k[s]--;
}

void push_val(ll s){
    power += 2*k[s]*s + s;
    k[s]++;
}

void solve(){
    int s = q[0].s,  e = q[0].e;
    for(int i=q[0].s; i<=q[0].e; i++) push_val(arr[i]);
    for(int i=0; i<m; i++){
        while(s > q[i].s) push_val(arr[--s]);
        while(e < q[i].e) push_val(arr[++e]);
        while(s < q[i].s) pop_val(arr[s++]);
        while(e > q[i].e) pop_val(arr[e--]);
        ans[q[i].idx] = power;
    }
    for(int i=0; i<m; i++) cout << ans[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
}