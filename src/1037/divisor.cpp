#include <cstdio>

int main(){
	int n, mx = 0, mn = 1000000;
	scanf("%d", &n);
	while(n--){
		int temp;
		scanf("%d", &temp);
		mx = temp>mx?temp:mx;
		mn = temp<mn?temp:mn;
	}
	printf("%d", mx*mn);
	return 0;
}
