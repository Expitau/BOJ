#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<pair<int, int>> dque;

int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	for(int i=0; i<n; i++){
		int k;
		scanf("%d", &k);
		if(!dque.empty() && dque.front().second <= i-l) dque.pop_front();
		while(!dque.empty() && dque.back().first > k) dque.pop_back();
		dque.push_back({k, i});
		printf("%d ", dque.front().first);
	}
	return 0;
}
