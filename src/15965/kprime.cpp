#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAX = 10000000;
bool arr[MAX];

int main(){
	ll k, t = 0;
	scanf("%lld", &k);
	for(ll i=2; i<MAX; i++){
		if(arr[i]) continue;
		t++;
		if(t == k){
			printf("%lld", i);
			break;
		}
		for(ll j=i*i; j<MAX; j+=i) arr[j] = 1;
	}
	return 0;
}
