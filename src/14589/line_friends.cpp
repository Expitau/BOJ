#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class data{
public:
	int s, e;
	data(int _s, int _e):s(_s),e(_e){}
};
data arr[200000];

int main(){
	int n, q;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &arr[i].s, &arr[i].e);
	}
	scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n");
	}
	return 0;
}
/**
shortest path(all pair) in interval graph.....
  **/
