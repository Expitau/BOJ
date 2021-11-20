#include <cstdio>
#include <queue>
using namespace std;
queue<int> que;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) que.push(i);
	printf("<");
	while(!que.empty()){
		if(que.size() == 1){
			printf("%d>", que.front());
			break;
		}
		for(int i=1; i<m; i++){
			que.push(que.front());
			que.pop();
		}
		printf("%d, ", que.front());
		que.pop();
	}
	return 0;
}
