#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> adj[330];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a < b) adj[a].push_back({b,c});
	}

	return 0;
}
