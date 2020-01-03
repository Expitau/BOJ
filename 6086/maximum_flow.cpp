#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int capa[60][60], worked[60], flow[60][60], level[60];
vector<int> adj[60];

int dfs(int now, int end, int min_flow){
	if(now == end)
		return min_flow;
    
	for(int & i=worked[now]; i<adj[now].size(); i++){
        int next = adj[now][i];
        if(level[next] == level[now] + 1 && capa[now][next]-flow[now][next] > 0){
			int temp = dfs(next, end, min(min_flow, capa[now][next]-flow[now][next]));
			if(temp > 0){
				flow[now][next] += temp;
				flow[next][now] -= temp;
				return temp;
			}
		}
	}
    
	return 0;
}

bool make_level_graph(int start, int end){
    queue<int> que;
    fill(level, level+60, -1);
    que.push(start);
    level[start] = 0;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto next : adj[now]){
            if(capa[now][next] - flow[now][next] > 0 && level[next] == -1){
                level[next] = level[now]+1;
                que.push(next);
            }
        }
    }
    return level[end] != -1;
}

int ctoi(char c){
    if(c <= 'Z') return c-'A'+1;
    return c-'a'+27;
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
    
	//dinnic
	int ans = 0, start = ctoi('A'), end = ctoi('Z');
	while(make_level_graph(start, end)){
		fill(worked, worked+60, 0);
		while(1){
			int temp = dfs(start, end, 2e9);
			if(!temp) break;
			ans += temp;
		}
	}
	printf("%d", ans);
	return 0;
}
