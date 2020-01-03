#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100100];
int child_cnt[100100], par[100100], dep[100100];
int Num[100100], HLD[100100], HLD_head[100100], HLD_count;
int tree[400100], lazy[400100];
int n, m;

void get_child_cnt(int now, int pre = 0){
    par[now] = pre;
    dep[now] = dep[pre]+1;
    adj[now].erase(remove(adj[now].begin(), adj[now].end(), pre), adj[now].end());
    for(auto it : adj[now]){
        get_child_cnt(it, now);
        child_cnt[now] += child_cnt[it] + 1;
    }
}

void renumber(int now, int num = 0){// 연속된 구간을 가지도록 해준다
    sort(adj[now].begin(), adj[now].end(), [](int a, int b)->bool{
        return child_cnt[a] > child_cnt[b];
    });
    Num[now] = ++num;
    for(auto it : adj[now]){
        renumber(it, num);
        num += child_cnt[it] + 1;
    }
}

void make_HLD(int now, bool is_head = 1){ // group을 만들어 준다
    if(is_head){
        HLD_count++;
        HLD_head[HLD_count] = now;
    }
    HLD[now] = HLD_count;
    for(int i=0; i<adj[now].size(); i++)
        make_HLD(adj[now][i],i);
}

void propagate(int now, int l, int r){ // lazy 해소
    if(l != r){
        lazy[now*2] += lazy[now];
        lazy[now*2+1] += lazy[now];
    }
    tree[now] += lazy[now] * (r-l+1);
    lazy[now] = 0;
}

void seg_update(int now, int l, int r, int s, int e, int diff){
    if(s > e) return;
    
    if(l > e || r < s)
        return;
    
    propagate(now, l, r);
    
    if(s <= l && r <= e){
        lazy[now] += diff;
        propagate(now, l, r);
        return;
    }
    
    int m = (l+r)/2;
    seg_update(now*2, l, m, s, e, diff);
    seg_update(now*2+1, m+1, r, s, e, diff);
    tree[now] = tree[now*2]+tree[now*2+1];
}

int seg_query(int now, int l, int r, int s, int e){
    if(s > e) return 0;
    
    if(l > e || r < s)
        return 0;
    
    propagate(now, l, r);
    
    if(s <= l && r <= e)
        return tree[now];
    
    int m = (l+r)/2;
    return seg_query(now*2, l, m, s, e) + seg_query(now*2+1, m+1, r, s, e);
}

void update(int s, int e, int diff = 1){
    while(HLD[s] != HLD[e]){
        if(dep[HLD_head[HLD[s]]] > dep[HLD_head[HLD[e]]])
            swap(s, e);
        seg_update(1, 1, n, Num[HLD_head[HLD[e]]], Num[e], diff);
        e = par[HLD_head[HLD[e]]];
    }
    if(Num[s] > Num[e])
        swap(s, e);
    seg_update(1, 1, n, Num[s]+1, Num[e], diff);
}

int query(int s, int e){
    int res = 0;
    while(HLD[s] != HLD[e]){
        if(dep[HLD_head[HLD[s]]] > dep[HLD_head[HLD[e]]])
            swap(s, e);
        res += seg_query(1, 1, n, Num[HLD_head[HLD[e]]], Num[e]);
        e = par[HLD_head[HLD[e]]];
    }
    if(Num[s] > Num[e])
        swap(s, e);
    res += seg_query(1, 1, n, Num[s]+1, Num[e]);
    return res;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    get_child_cnt(1);
    renumber(1);
    make_HLD(1);
    
    for(int i=0; i<m; i++){
        char type;
        int a, b;
        scanf(" %c %d %d", &type, &a, &b);
        if(type == 'P')
            update(a, b);
        else
            printf("%d\n", query(a, b));
    }
    return 0;
}

