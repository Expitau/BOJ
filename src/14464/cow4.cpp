#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> que;
int tarr[20200];
pair<int, int> arr[20200];

int main(){
    int c, n;
    scanf("%d %d", &c, &n);
    for(int i=0; i<c; i++) scanf("%d", tarr+i);
    for(int i=0; i<n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(tarr, tarr+c); sort(arr, arr+n);
    int k = 0, ans = 0;
    for(int i=0; i<c; i++){
        while(k < n && arr[k].first <= tarr[i]) que.push(arr[k++].second);
        while(!que.empty() && que.top() < tarr[i]) que.pop();
        if(!que.empty()) ans++, que.pop();
    }
    printf("%d", ans);
    return 0;
}
