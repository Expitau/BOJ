#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
class Point{
public:
    ll x, y;
    Point(){}
    Point(ll _x, ll _y){
        x = _x; y = _y;
    }
    Point operator-(const Point & P) const {
        return {x-P.x, y-P.y};
    }
    void input(){
        scanf("%lld %lld", &x, &y);
    }
};

int ccw(Point a, Point b, Point c){
    ll t = a.x*b.y + b.x*c.y + c.x*a.y;
    t -= a.y*b.x + b.y*c.x + c.y*a.x;
    if(t > 0) return 1;
    if(t == 0) return 0;
    return -1;
}

ll getSize(Point a){
    return a.x*a.x + a.y*a.y;
}

void convex_hull(vector<Point> &L, vector<Point> &R){
    int mn = 0;
    for(int i=0; i<L.size(); i++)
        if(L[i].y < L[mn].y || (L[i].y == L[mn].y && L[i].x > L[mn].x))
            mn = i;
    swap(L[mn], L[0]);
    sort(L.begin()+1, L.end(), [&](Point & l, Point & r)->bool{
        if(ccw(L[0], l, r) != 0) return ccw(L[0], l, r) > 0;
        return getSize(l-L[0]) < getSize(r-L[0]);
    });
    
    for(int i=0; i<L.size(); i++){
        while(R.size() >= 2 && ccw(R[R.size()-2], R.back(), L[i]) <= 0)
            R.pop_back();
        R.push_back(L[i]);
    }
}

vector<Point> arr, ch;

int main(){
    int n;
    scanf("%d", &n);
    arr.resize(n);
    for(int i=0; i<n; i++) arr[i].input();
    convex_hull(arr, ch);
    printf("%lu", ch.size());
    return 0;
}
