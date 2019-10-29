#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Query{
public:
	int s, e, idx;
	Query(){}
	Query(int _s, int _e, int _i):s(_s),e(_e),idx(_i){}
};

vector<Query> q;
int arr[100100], cnt[100100], Aans[100100], ans;

void add(int num){
	if(++cnt[num] == 1){
		ans++;
	}
}
void erase(int num){
	if(--cnt[num] == 0){
		ans--;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	int m;
	scanf("%d", &m);
	q.resize(m);	
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		q[i] = {a-1, b-1, i};
	}
	int sz = sqrt(n);
	sort(q.begin(), q.end(), [&](const Query & a, const Query & b){
			int lIdx = a.s / sz;
			int rIdx = b.s / sz;
			return lIdx == rIdx ? a.e < b.e : lIdx < rIdx;
	});

	int s = 0, e = 0;
	add(arr[0]);
	for(auto it :  q){
		int ns = it.s, ne = it.e;
		for(int i=s; i<ns; i++)
			erase(arr[i]);
		for(int i=s-1; i >= ns; i--)
			add(arr[i]);
		for(int i=e+1; i<=ne; i++)
			add(arr[i]);
		for(int i=e; i>ne; i--)
			erase(arr[i]);
		s = ns, e = ne;
		Aans[it.idx] = ans;
	}
	for(int i=0; i<m; i++) printf("%d\n", Aans[i]);
	return 0;
}
