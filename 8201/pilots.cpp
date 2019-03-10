#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii> Mque;
priority_queue<pii, vector<pii>, greater<pii>> mque;

int main(){
	int k, n, temp, last_i=0, ans = 0; 
	scanf("%d %d", &k, &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &temp);
		Mque.push({temp, i}); mque.push({temp, i});
		while(Mque.top().first- mque.top().first > k || Mque.top().second < last_i || mque.top().second < last_i){
			if(Mque.top().second < mque.top().second){
				last_i=max(last_i, Mque.top().second);
				Mque.pop();
			}else{
				last_i=max(last_i, mque.top().second);
				mque.pop();
			}
		}
		ans = max(ans, i-last_i);
	}
	printf("%d", ans);
	return 0;
}
