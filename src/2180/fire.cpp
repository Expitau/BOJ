#include <cstdio>
#include <algorithm>
using namespace std;

class data{
public:
	int a, b;
	bool operator<(const data & D) const {
		return a*D.b + b > D.a*b + D.b;
	}
};

data arr[200200];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d %d", &arr[i].a, &arr[i].b);
	sort(arr, arr+n);
	int ans = 0;
	for(int i=0; i<n; i++)
		printf("%d %d\n", arr[i].a, arr[i].b),ans = ((arr[i].a*ans)%40000+arr[i].b)%40000;
	printf("%d", ans);
	return 0;
}
