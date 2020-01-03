#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

void update(vector<ll> & tree, int i, ll diff){
	while(i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

ll get_sum(vector<ll> & tree, int i){
	ll ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int arr[100100];
vector<ll> tree1, tree2;

int main(){
	int n;
	scanf("%d", &n);
	tree1.resize(n+1);
	tree2.resize(n+1);
	for(int i=0; i<n; i++) scanf("%d", arr+i);

	ll ans = 0;
	for(int i=n-1; i>=0; i--){
		int now = arr[i];

		update(tree1, now, 1);
		if(now > 1){
			update(tree2, now, get_sum(tree1, now-1));
			ans += get_sum(tree2, now-1);
		}
	}

	printf("%lld", ans);
	return 0;
}
