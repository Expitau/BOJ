#include <iostream>
#include <algorithm>

using namespace std;


class Area{
public: 
    int idx, sx, ex, sy, ey, mx, my;

    Area(int idx, int sx, int ex, int sy, int ey):idx(idx),sx(sx),ex(ex),sy(sy),ey(ey){
        mx = (sx+ex)/2;
        my = (sy+ey)/2;
    }

    Area LU(){
        return Area(idx*4, sx, mx, sy, my);
    }
    Area RU(){
        return Area(idx*4+1, mx+1, ex, sy, my);
    }
    Area LD(){
        return Area(idx*4+2, sx, mx, my+1, ey);
    }
    Area RD(){
        return Area(idx*4+3, mx+1, ex, my+1, ey);
    }

    bool include(Area a){
        return sx <= a.sx && a.ex <= ex && sy <= a.sy && a.ey <= ey;
    }
    bool disjoint(Area a){
        return (ex < a.sx || a.ex < sx) || (ey < a.sy || a.ey < sy);
    }

    bool leaf(){
        return (sx == ex) || (sy == ey);
    }

    void print(){
        cout << sx << " " << ex << " " << sy << " " << ey << "\n";
    }
};

class Box{
public:
    int sx, sy, ex, ey, lz, z;

    Box(){}

    void get_input(){
        int lx, ly;
        cin >> lx >> ly >> lz >> sx >> sy;
        ex = lx + sx;
        ey = ly + sy;
        sx++; sy++;
    }

    Area get_area(){
        return Area(0, sx, ex, sy, ey);
    }
};

int tree[1024*1024*9];
int lazy[1024*1024*9];

inline void update(int & a, const int b){
    a = max(a,b);
}

inline void prop_lazy(Area a){
    int i = a.idx;
    if (lazy[i] != 0) {
        tree[i] = lazy[i];
        lazy[i] = 0;
        if(a.leaf()) return;
        lazy[4*i] = lazy[4*i+1] = lazy[4*i+2] = lazy[4*i+3] = tree[i];
    }
}

Area init_area(){
    return Area(1, 1, 1024, 1, 1024);
}

void update_range(Area r, Area a, int h){
    int i = r.idx;

    prop_lazy(r);

    if(a.include(r)){
        tree[i] = h;
        if(r.leaf()) return;
        lazy[4*i] = lazy[4*i+1] = lazy[4*i+2] = lazy[4*i+3] = h;
        return;
    }

    if(a.disjoint(r) || r.leaf()) return;
    
    update_range(r.LU(), a, h); update_range(r.RU(), a, h); update_range(r.LD(), a, h); update_range(r.RD(), a, h);
    tree[i] = max({tree[4*i],tree[4*i+1],tree[4*i+2],tree[4*i+3]});
}

int get_max(Area r, Area a, int prev_max=0){
    prop_lazy(r);

    // early stopping
    if(tree[r.idx] <= prev_max) return 0;

    if(a.include(r)) return tree[r.idx];
    if(a.disjoint(r) || r.leaf()) return 0;

    int ret = get_max(r.LU(), a);
    update(ret, get_max(r.RU(), a, ret));
    update(ret,  get_max(r.LD(), a, ret));
    update(ret, get_max(r.RD(), a, ret));
    
    return ret;
}



void update_range(Area a, int h){ update_range(init_area(), a, h); }

int get_max(){ return get_max(init_area(), init_area()); }

int get_max(Area a){ return get_max(init_area(), a); }

void solve(){
    int lx, ly, n;
    Box b;
    cin >> lx >> ly >> n;

    for(int i=0; i<n; i++) {
        b.get_input();
        int z = get_max(b.get_area()) + b.lz;
        update_range(b.get_area(), z);
    }

    cout << get_max() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}