#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
pii land[50050];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d %d", &land[i].first, &land[i].second);
	sort(land+1, land+n+1);
	for(int i=1; i<=n; i++){

	}
	return 0;
}

/*
	d[i] = i 번땅까지 살때의 최소 비용
	d[i] = (j<i)min(d[j] + arr[j].first*max(j<k<=i)(arr[k].second));

   */

