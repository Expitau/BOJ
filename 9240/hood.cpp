#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll=long long;

class point{
public:
	ll x, y;
	point(){}
	point(ll X, ll Y){x = X; y = Y;}
	
	void getInput(){
		scanf("%lld %lld", &x, &y);
	}	
	
	bool operator<(const point & P)const{
		if(x != P.x) return x < P.x;
		return y < P.y;
	}
	
	point operator-(const point & P)const{
		return {x-P.x, y-P.y};
	}
};

point arr[100100], topConvex[100100], botConvex[100100];
int topSize, botSize, n;

ll getDist(point A, point B){
	point t = A-B;
	return t.x*t.x + t.y*t.y;
}

void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
       arr[i].getInput();
	}
	sort(arr, arr+n);
}

int ccw(point a, point b, point c){
	b = b-a;
	c = c-a;
	ll temp = b.x*c.y- b.y*c.x;
	if(temp > 0) return 1;
	else if(temp == 0) return 0;
	return -1;
}

bool update(point * C, int & Si, int Sg){
	if(ccw(C[Si-3],C[Si-2],C[Si-1]) != Sg){
		C[Si-2] = C[Si-1];
		Si--;
		return true;
	}
	return false;
}

void getConvex(){
	topConvex[topSize++] = arr[0];
	botConvex[botSize++] = arr[0];

	for(int i=1; i<n; i++){
		bool flag = 1;
		
		topConvex[topSize++] = arr[i];
		while(topSize > 2 && flag){
			flag = update(topConvex, topSize, -1);
		}
	
		flag = 1;
		botConvex[botSize++] = arr[i];
		while(botSize > 2 && flag){
			flag = update(botConvex, botSize, 1);
		}
		//printf("%d : %d %d\n", i, topSize, botSize);
	}
}

double getDiam(){
	int bot = 0, top = topSize - 1;
	ll ans = 0;
	
	while(bot+1 < botSize && top > 0){
		double dist = getDist(botConvex[bot], topConvex[top]);
		if(dist > ans) ans = dist;
		
		point B = botConvex[bot] - botConvex[bot+1];
		point T = topConvex[top-1] - topConvex[top];
		if(T.x*B.y - T.y*B.x > 0){
			top--;
		}else{
			bot++;
		}
	}
	
	ll dist = getDist(botConvex[bot], topConvex[top]);
	if(dist > ans) ans = dist;
	
	return sqrt(ans);
}

int main(){
	input();
	getConvex();
	
	//printf("haha\n");
	//for(int i=0; i<botSize; i++) printf("%lld %lld \n", botConvex[i].x, botConvex[i].y);
	//printf("haha\n");
	//for(int i=0; i<topSize; i++) printf("%lld %lld \n", topConvex[i].x, topConvex[i].y);
	
	double ans = getDiam();
	printf("%.8f", ans);
}
