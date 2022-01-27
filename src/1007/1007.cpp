#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

class Vec2{
public:
    ll x, y;

    Vec2():x(0),y(0){}
    Vec2(ll x, ll y):x(x),y(y){}

    void input(){
        cin >> x >> y;
    }

    Vec2 operator + (const Vec2 v) const{
        return {x+v.x, y+v.y};
    }
    Vec2 operator - (const Vec2 v) const{
        return {x-v.x, y-v.y};
    }

    ll sqnorm(){
        return x*x + y*y;
    }
};

void update_res(ll & res, ll candi){
    if(res == -1) res = candi;
    else if(candi != -1) res = min(res, candi);
}

ll get_ans(int now, int cnt, Vec2 ans1, Vec2 ans2, vector<Vec2> & vecs){
    if(vecs.size()-now < cnt) return -1;
    if(now == vecs.size() && cnt == 0){
        return (ans1-ans2).sqnorm();
    }

    ll res = -1;
    update_res(res, get_ans(now+1, cnt-1, ans1+vecs[now], ans2, vecs));
    update_res(res, get_ans(now+1, cnt, ans1, ans2+vecs[now], vecs));
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<Vec2> vecs(n);
    for(int i=0; i<n; i++) vecs[i].input();
    cout << fixed;
    cout.precision(6);
    cout << sqrt(get_ans(0, n/2, Vec2(), Vec2(), vecs)) << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}