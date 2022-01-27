#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

class Point{
public:
    ll x, y;
    Point(){}
    Point(ll X, ll Y):x(X),y(Y){}
    void input(){
        cin >> x >> y;
    }

    ll sqnorm(){
        return (x*x) + (y*y);
    }

    Point operator - (const Point p) const{
        return Point(x-p.x, y-p.y);
    }

    bool operator == (const Point p) const{
        return (p.x == x) && (p.y == y);
    }
};

vector<Point> points, ch;

int ccw(Point A, Point B, Point C){
    ll k = (A.x*B.y-A.y*B.x) + (B.x*C.y-B.y*C.x) + (C.x*A.y-C.y*A.x);
    if(k > 0) return 1;
    if(k == 0) return 0;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    points.resize(n);
       
    for(auto & p : points) p.input();
    
    sort(points.begin(), points.end(), [&](Point p1, Point p2){
            if(p1.y != p2.y) return p1.y < p2.y;
            return p1.x < p2.x;
        });

    points.erase(unique(points.begin(), points.end()), points.end());

    sort(points.begin()+1, points.end(), [&](Point p1, Point p2){
        int k = ccw(points[0], p1, p2);
        if(k > 0 || (k==0 && (points[0]-p1).sqnorm() < (points[0]-p2).sqnorm()))
            return true;
        return false;
    });


    for(auto p : points){
        while(ch.size() >= 2 && ccw(ch[ch.size()-2], ch[ch.size()-1], p) <= 0){
            ch.pop_back();
        }
        ch.push_back(p);
    }


    int j = 1%ch.size();
    ll ans = 0;
    for(int i=0; i<ch.size(); i++){
        int ni = (i+1)%ch.size();
        while(1){
            int nj = (j+1)%ch.size();
            if(nj != i && ccw({0,0}, ch[ni]-ch[i], ch[nj]-ch[j]) > 0) j = nj;
            else break;
        }
        ans = max(ans, (ch[i]-ch[j]).sqnorm());
    }

    cout << ans << "\n";

    return 0;
}
