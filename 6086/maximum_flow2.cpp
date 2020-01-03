#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int capa[60][60], flow[60][60], path[60];
vector<int> adj[60];

int ctoi(char k){
	if('A' <= k && k <= 'Z')
		return k-'A'+1;
	return k-'a'+27;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char a, b;
        int f;
        scanf(" %c %c %d", &a, &b, &f);
    	int s = ctoi(a), e = ctoi(b);  
		
		capa[s][e] += f;
		capa[e][s] += f;
		
		adj[s].push_back(e);
		adj[e].push_back(s);
    }
    
    int ans = 0, start = ctoi('A'), end = ctoi('Z');
 
    while(1){
        fill(path, path+60, -1);
 
        queue<int> que;
        que.push(start);

        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(auto it : adj[now]){
                if(capa[now][it]-flow[now][it] > 0 && path[it] == -1){
                    path[it] = now;
                    que.push(it);
                }
            }
        }

        if(path[end] == -1) break;
        
		int mn = 2e9;
        for(int i=end; i != start; i = path[i]){
            mn = min(mn, capa[path[i]][i] - flow[path[i]][i]);
        }
        for(int i=end; i != start; i = path[i]){
            flow[path[i]][i] += mn;
            flow[i][path[i]] -= mn;
        }
        ans += mn;
    }
 
    printf("%d", ans);
    
    return 0;
}
