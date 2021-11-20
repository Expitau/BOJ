#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
class Mat{
public:
	ll arr[2][2];
	ll[2][2] multi(const Mat & m, Mat & ret){
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				ret.arr[i][j] = 0;
				for(int k=0; k<2; k++) 
					ret.arr[i][j] += arr[i][k] * m.arr[i][k];
			}
		}
	}
};
const ll MOD = 1000000007;

int main(){
	ll n;
	scanf("%d", &n);
	for(ll i=1; (1<<i)<=n; i++){
		d[i-1].multi(d[i-1], d[i]);
	}

	return 0;
}
