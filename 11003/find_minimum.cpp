#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
class data{
public:
	int val, ind;
	data(int _v=0, int _i=0):val(_v),ind(_i){}
	bool operator<(const data & D)const{
		return val>D.val;
	}
};
priority_queue<data> que;
int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	for(int i=0; i<n; i++){
		int a; scanf("%d", &a);
		que.push({a, i});
		while(que.top().ind + l <= i) que.pop();
		printf("%d ", que.top().val);
	}
	return 0;
}
