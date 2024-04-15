/*

n . x . 3 2 1 1 2 3 . x . n
    
min_sum[x]
l_tail_sum[x]
r_tail_sun[x]

d[x]


*/


#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;

class Problem{
// UNCOMPED
ll N, c;
vector<ll> cost, ans;

// COMPED
vector<ll> comp_d, comp_cost;
string str;

void input(){
    cin >> N >> c;
    cin >> str;
    cost.resize(N);
    for(int i=0; i<N; i++){
        cin >> cost[i];
    }
}

void calculate_comp(){
    ll n;
    vector<ll> l_cost, r_cost, l_d, r_d, min_sum, l_tail_sum, r_tail_sum;
    vector<ll> l_min_i1, l_min_i2, r_min_i1, r_min_i2;
    
    // [COMPRESS] 
    /// calcuate l_cost, l_d, r_cost, r_d, min_sum 
    l_cost.push_back(0); l_d.push_back(0);
    r_cost.push_back(0); r_d.push_back(0);
    min_sum.push_back(0); 

    for(int i=(N-1)/2, j=N/2; j < N; i--, j++){
        if(str[i] == str[j]) continue;
        l_cost.push_back(cost[i]); l_d.push_back(i);
        r_cost.push_back(cost[j]); r_d.push_back(j);
        min_sum.push_back(*min_sum.rbegin() + min(cost[i], cost[j]));
    }
    l_d[0] = r_d[1];
    r_d[0] = l_d[1];

    n = l_cost.size()-1;

    if(n == 0){
        comp_d.resize(0);
        comp_cost.resize(0);
        return;
    }

    /// calcualte l_tail_sum, r_tail_sum
    l_tail_sum.resize(n+3); r_tail_sum.resize(n+3);
    for(int i=n; i>=0; i--){
        l_tail_sum[i] = l_tail_sum[i+1] + l_cost[i];
        r_tail_sum[i] = r_tail_sum[i+1] + r_cost[i];
    }
    
    /*
    /// [n.....x.|....i]....n
    /// total_l(x,i) = c*(d[x]-2*l_d[n]) + c*r_d[i]   + (l_tail_sum[i+1] + min_sum[i])
    ///                c*(-d[x]-l_d[n])  + 2*c*r_d[i] + (l_tail_sum[i+1] + min_sum[i])
    /// 
    /// [n.....x.|....i]....n
    /// total_l_l(x) = c*(l_d[x]-2*l_d[n])  + l_min_i1[0] 
    ///                c*(-l_d[x]-l_d[n])   + l_min_i2[0]
    /// [n.......|..x.i]....n
    /// total_l_r(x) = c*(r_d[x]-2*l_d[n])  + l_min_i1[x]
    ///                c*(-r_d[x]-l_d[n])   + l_min_i2[x]
    ///
    /// n...[i....|..x.....n]
    /// total_r(x,i) = c*(-d[x]+2*r_d[n])   + (-c*l_d[i])   + (r_tail_sum[i+1] + min_sum[i])
    ///                c*(d[x]+r_d[n])      + (-2*c*l_d[i]) + (r_tail_sum[i+1] + min_sum[i])
    ///
    /// n...[i....|..x.....n]
    /// total_r_r(x) = c*(-r_d[x]+2*r_d[n]) + r_min_i1[0] 
    ///                c*(r_d[x]+r_d[n])    + r_min_i2[0]
    /// n...[i.x..|........n]
    /// total_r_l(x) = c*(-l_d[x]+2*r_d[n]) + r_min_i1[x]
    ///                c*(l_d[x]+r_d[n])    + r_min_i2[x]
    ///
    */
    
    auto l_i1 = [&](int i){return c*r_d[i]      + (l_tail_sum[i+1] + min_sum[i]);};
    auto l_i2 = [&](int i){return 2*c*r_d[i]    + (l_tail_sum[i+1] + min_sum[i]);};
    auto r_i1 = [&](int i){return (-c*l_d[i])   + (r_tail_sum[i+1] + min_sum[i]);};
    auto r_i2 = [&](int i){return (-2*c*l_d[i]) + (r_tail_sum[i+1] + min_sum[i]);};

    l_min_i1.resize(n+1);l_min_i2.resize(n+1);r_min_i1.resize(n+1);r_min_i2.resize(n+1);
    l_min_i1[n]=l_i1(n); l_min_i2[n]=l_i2(n); r_min_i1[n]=r_i1(n); r_min_i2[n]=r_i2(n);

    for(int i=n-1; i>=0; i--){
        l_min_i1[i] = min(l_min_i1[i+1], l_i1(i));
        l_min_i2[i] = min(l_min_i2[i+1], l_i2(i));
        r_min_i1[i] = min(r_min_i1[i+1], r_i1(i));
        r_min_i2[i] = min(r_min_i2[i+1], r_i2(i));
    }

    for(int x=n; x>0; x--) {
        comp_d.push_back(l_d[x]);
        comp_cost.push_back(min({ 
            c*(l_d[x]-2*l_d[n])  + l_min_i1[0],
            c*(-l_d[x]-l_d[n])   + l_min_i2[0],
            c*(-l_d[x]+2*r_d[n]) + r_min_i1[x],
            c*(l_d[x]+r_d[n])    + r_min_i2[x]
        }));
    }
    for(int x=1; x<=n; x++){
        comp_d.push_back(r_d[x]);
        comp_cost.push_back(min({ 
            c*(-r_d[x]+2*r_d[n]) + r_min_i1[0],
            c*(r_d[x]+r_d[n])    + r_min_i2[0],
            c*(r_d[x]-2*l_d[n])  + l_min_i1[x],
            c*(-r_d[x]-l_d[n])   + l_min_i2[x]
        }));
    }

}

void calculate_decomp(){
    ans.resize(N);

    ll n = comp_d.size();
    if(n == 0) return;

    for(ll i=0; i<comp_d[0]; i++){
        ans[i] = comp_cost[0] + c*(comp_d[0]-i);
    }

    for(ll i=comp_d[n-1]; i<N; i++){
        ans[i] = comp_cost[n-1] + c*(i-comp_d[n-1]);
    }

    for(ll k=0; k<n-1; k++){
        for(ll i=comp_d[k]; i<comp_d[k+1]; i++){
            ans[i] = min({
                comp_cost[k]   + c*(i-comp_d[k]),
                comp_cost[k+1] + c*(comp_d[k+1]-i)
            });
        }
    }
}

public:
    Problem(){
        input();
        calculate_comp();
        calculate_decomp();
    }

    void print_sol(){
        for(int i=0; i<N; i++) cout << ans[i] << " ";
        cout << "\n";
    }
};




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        Problem * p = new Problem();
        p->print_sol();
    }

    return 0;
}