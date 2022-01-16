#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int mp[1000100];
int arr[1000100], tmp[1000100];
int ans[1000100];
tiii query[1000100];
int n, m, mp_size;

void push_value(int a){
    if(mp[a] == 0) mp_size++;
    mp[a] += 1;
}

void pop_value(int a){
    mp[a] -= 1;
    if(mp[a] == 0) mp_size--;
}

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) {cin >> arr[i]; tmp[i] = arr[i];}
    sort(tmp+1, tmp+n+1); int k = unique(tmp+1, tmp+n+1) - tmp;
    for(int i=1; i<=n; i++) arr[i] = lower_bound(tmp+1, tmp+k, arr[i]) - tmp;

    cin >> m;
    for(int i=0; i<m; i++) {cin >> get<0>(query[i]) >>  get<1>(query[i]); get<2>(query[i]) = i;}
    sort(query, query+m, [](tiii a, tiii b){
        if(get<0>(a)/2000 != get<0>(b)/2000) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });
}

void solve(){
    int s = get<0>(query[0]), e = get<1>(query[0]);
    for(int i=s; i<=e; i++) push_value(arr[i]);
    for(int i=0; i<m; i++){
        while(s < get<0>(query[i])) pop_value(arr[s++]);
		while(s > get<0>(query[i])) push_value(arr[--s]);
		while(e < get<1>(query[i])) push_value(arr[++e]);
		while(e > get<1>(query[i])) pop_value(arr[e--]);
        ans[get<2>(query[i])] = mp_size;
    }
    for(int i=0; i<m; i++) cout << ans[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}