#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int amt[550][550], parcnt[550], arr[550];
queue<int> que, ans;

void init(){
	for(int i=0; i<=500; i++){
		parcnt[i] = 0;
		arr[i] = 0;
		for(int j=0; j<=500; j++) 
			amt[i][j] = 0;
	}
	while(!que.empty()) que.pop();
	while(!ans.empty()) ans.pop();
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		init();
		int n, k;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", arr+i);
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				amt[arr[i]][arr[j]] = 1;
				parcnt[arr[j]]++;
			}
		}	
		scanf("%d", &k);
		for(int i=0; i<k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			if(amt[a][b]) swap(a, b);
			amt[a][b] = 1;
			amt[b][a] = 0;
			parcnt[a]--; parcnt[b]++;
		}	
		for(int i=1; i<=n; i++)
			if(parcnt[i] == 0) que.push(i);

		while(!que.empty()){
			if(que.size() != 1) break;
			int now = que.front();
			que.pop();
			ans.push(now);
			parcnt[now] = 2e9;
			for(int i=1; i<=n; i++){
				parcnt[i] -= amt[now][i];
				if(!parcnt[i]) que.push(i);
			}
		}
		if(ans.size() != n) printf("IMPOSSIBLE\n");
		else{
			while(!ans.empty()) printf("%d ", ans.front()), ans.pop();
			printf("\n");
		}
	}
	return 0;
}
