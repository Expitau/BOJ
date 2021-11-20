#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(){
	int n, t, temp;
	scanf("%d", &n);
    arr.resize(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    scanf("%d", &t);
	while(t--){
		scanf("%d", &temp);
        if(*lower_bound(arr.begin(), arr.end(), temp) == temp) printf("1\n");
        else printf("0\n");
	}
	return 0;
}
