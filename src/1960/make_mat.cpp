#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii> pq;
stack<pii> stk;

int arr[550], ans[550][550];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
        if(a != 0)
            pq.push({a, i});
	}

	bool flag = 1;

	for(int i=0; i<n; i++){
		for(int j=0; j<arr[i]; j++){
			if(pq.empty()){
				flag = 0;
				break;
			}
			ans[i][pq.top().second] = 1;
			if(pq.top().first-1 > 0)
				stk.push({pq.top().first-1, pq.top().second});
			pq.pop();
		}
		if(!flag) break;
		while(!stk.empty()){
			pq.push(stk.top());
			stk.pop();
		}
	}
	if(!pq.empty()) flag = 0;

	if(flag){
		printf("1\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}else printf("-1\n");
	return 0;
}
