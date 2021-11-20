#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main(){
	int n;
	scanf("%d", &n);
	arr.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for(auto i : arr) printf("%d ", i);
	return 0;
}
