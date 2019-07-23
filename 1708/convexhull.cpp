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


void convex_hull(vector<Point> &L, vector<Point> &ch){
    for(Point p3 : L){
        while(ch.size() >= 2){
            int l = ch.size();
            Point &p1 = ch[l - 2];
            Point &p2 = ch[l - 1];
            if(ccw(p1, p2, p3) > 0)
                break;
            ch.pop_back();
        }
        ch.push_back(p3);
    }
}

vector<Point> arr, upch, downch;

int main(){
    int n;
    scanf("%d", &n);
    arr.resize(n);
    for(int i=0; i<n; i++)
        arr[i].input();
    int ans = -2;
    // up convex_hull
    sort(arr.begin(), arr.end(), [](Point A, Point B)->bool{
        if(A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    });
    convex_hull(arr, upch);
    // down comvex_hull
    reverse(arr.begin(), arr.end());
    convex_hull(arr, downch);
    
    printf("%lu", upch.size()+downch.size()-2);
    return 0;
}
/*
 (p2.x-p1.x)*(p3.y-p2.y) - (p2.y-p1.y)(p3.x-p2.x)
 
 2x3y
 -1x3y
 1x2y
 -3x2y
 +3x1y
 -2x1y
*/
