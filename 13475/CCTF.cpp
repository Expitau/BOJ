#include <cstdio>
#include <algorithm>
using namespace std;

class data{
public:
	int a, b, n;
	data(int A=0, int B=0, int N=0){a=A;b=B;n=N;}
};
data arr[100100];
int ans[100100], tree[1001000], n;

void update(int k){
	while(k <= n){
		tree[k] += 1;
		k += (k & (-k));
	}
}
int query(int k){
	int sum = 0;
	while(k > 0){
		sum += tree[k];
		k -= (k & (-k));
	}
	return sum;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &arr[i].a, &arr[i].b);
		arr[i].n = i;
	}
	sort(arr, arr+n, [](const data & A, const data & B)->bool{return A.a>B.a;});
	for(int i=0; i<n; i++){
		ans[arr[i].n] = n - i + query(arr[i].b) - 1;
		update(arr[i].b);
	}
	for(int i=0; i<n; i++) printf("%d\n", ans[i]);
	return 0;
}
