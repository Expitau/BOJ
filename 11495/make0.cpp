#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int pos[100010], tree[200010], n, m;

int sum(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, int diff){
	while(i <= n+m){
		tree[i] += diff;
		i += (i & -i);
	}
}

void solve(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<=n+m+1; i++)
		tree[i] = 0;

	for(int i=1; i<=n; i++){
		pos[i] = n-i+1;
		update(pos[i], 1);	
	}

	for(int i=0; i<m; i++){
		int k;
		scanf("%d", &k);
		printf("%d ", n - sum(pos[k]));
		update(pos[k], -1);
		pos[k] = n+i+1;
		update(pos[k], 1);
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}
