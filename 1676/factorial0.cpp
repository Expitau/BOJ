#include <cstdio>

int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int temp = i;
		while(temp%5==0){
			temp/=5;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
