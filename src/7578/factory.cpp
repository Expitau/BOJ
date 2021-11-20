#include <cstdio>
#include <map>
using namespace std;

int arr1[1000500];
int bit[500500], n;
map<int, int> mp;

void update(int k){
	while(k <= n){
		bit[k]++;
		k += k&(-k);
	}
}

int sum(int k){
	int sum = 0;
	while(k > 0){
		sum += bit[k];
		k -= k&(-k);
	}
	return sum;
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        arr1[temp] = i;
	}
	long long res = 0;
	for(int i=1; i<=n; i++){
        int temp;
		scanf("%d", &temp);
		temp = arr1[temp];
		res += i - 1 - sum(temp);
		update(temp);
	}
	printf("%lld", res);
	
	return 0;
}
