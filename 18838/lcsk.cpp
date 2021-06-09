#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using pll = pair<long, long>;
using ll = long long;

ll arr[100100];
ll N, K;
const ll INF = 9e18;
ll L[100100], C[100100];
pll tree[500400];
vector<ll> ans;
vector<ll> I[100100];

ll safe_add(ll a, ll b){
    ll res = a+b;
    if (a > K || b > K || res > K) return INF;
    return res;
}

void update(int now, int l, int r, int k, pll diff){
    if(l > k || r < k) return;
    if(l == r){
        tree[now] = diff;
        return;
    }

    int ln = now*2, rn = now*2+1, m = (l+r)/2;
    update(ln, l, m, k, diff);
    update(rn, m+1, r, k, diff);

    if(tree[ln].first != tree[rn].first) 
        tree[now] = tree[ln].first>tree[rn].first?tree[ln]:tree[rn];
    else
        tree[now] = {tree[ln].first, safe_add(tree[ln].second, tree[rn].second)};
}

pll getAns(int now, int l, int r, int s, int e){
    if(l > e || r < s) return {0, 0};
    if(s <= l && r <= e) return tree[now];

    int ln = now*2, rn = now*2+1, m = (l+r)/2;
    pll lt = getAns(ln, l, m, s, e);
    pll rt = getAns(rn, m+1, r, s, e);

    pll res;
    if(lt.first != rt.first) res = lt.first>rt.first?lt:rt;
    else res  = {lt.first, safe_add(lt.second, rt.second)};
    return res;
}

int main(){
    scanf("%lld %lld", &N, &K);

    for(int i=1; i<=N; i++){
       scanf("%lld", arr+i); 
    }

    for(int i=N; i>0; i--){
        ll nowA = arr[i];
        pll temp = getAns(1, 1, N+1, nowA, N+1);
        if(temp.first == 0 && temp.second == 0)
            temp = {1,1};
        else
            temp.first++;
        update(1, 1, N+1, nowA, temp);
        L[i] = temp.first, C[i] = temp.second;
    }

    ll L_max = 0;
    
    for(int i=1; i<=N; i++){
        //printf("%lld : %lld %lld\n", arr[i], L[i], C[i]);
        I[L[i]].push_back(i);
        L_max = max(L[i], L_max);
    }
    
    ll total_lis = getAns(1, 1, N+1, 1, N+1).second;
    //printf("total_lis : %d\n", total_lis);

    if(total_lis < K){
        printf("-1");
    }else{
        ll now_k = 0, last_i = 0;
        for(int i=L_max; i > 0; i--){
            sort(I[i].begin(), I[i].end(), [&](const ll & a, const ll & b){return arr[a] != arr[b] ? arr[a] < arr[b] : a < b;});
            for(auto it : I[i]){
                if(it < last_i) continue;

                ll tmp = safe_add(now_k, C[it]);
                if(tmp >= K){
                    ans.push_back(it);
                    last_i = it;
                    break;
                }
                now_k = tmp;
            }
        }
        for(auto it : ans) printf("%lld ", arr[it]);
    }

    return 0;
}