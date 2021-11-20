#include <cstdio>
using namespace std;
class point{
public:
	int x, y;
	point(int _x=0, int _y=0):x(_x),y(_y){}
	void input(){
		scanf("%d %d", &x, &y);
	}
};

inline bool isIn(point a, point c, int r){
	return (a.x-c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y) <= r*r;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		point s, e;
		s.input(); e.input();
		int n, ans = 0;
		scanf("%d", &n);
		while(n--){
			int r;
			point c;
			c.input(); scanf("%d", &r);
			if(isIn(s, c, r)^isIn(e, c, r)) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
