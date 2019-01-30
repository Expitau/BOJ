#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[1100], Ftime[1100], prt[1100];
vector<int> child[1100];
queue<int> que;

void init(){
	while(!que.empty()) que.pop();
	for(int i=0; i<1100; i++){
		arr[i] = Ftime[i] = prt[i] = 0;
		child[i].clear();
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, w;
		init();
		scanf("%d %d", &n, &k);
		for(int i=1; i<=n; i++) scanf("%d", arr+i);
		for(int i=0; i<k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			prt[b]++;
			child[a].push_back(b);
		}
		scanf("%d", &w);
		for(int i=1; i<=n; i++) if(prt[i]==0){
			que.push(i);
			Ftime[i] = arr[i];
		}
		while(!que.empty()){
			int now = que.front(); que.pop();
			if(now == w){
				printf("%d\n", Ftime[now]);
				break;
			}
			for(auto it : child[now]){
				prt[it]--;
				Ftime[it] = max(Ftime[it], Ftime[now]);
				if(prt[it] == 0){
					Ftime[it] += arr[it];
					que.push(it);
				}
			}		
		}
	}
	return 0;
}
