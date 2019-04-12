#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> arr[10010000];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr+n);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i].first > ans) ans = arr[i].first;
        ans += arr[i].second;
    }
    printf("%d", ans);
    return 0;
}
