#include <cstdio>

using namespace std;

int ans[100100];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	if(n>k)
		printf("0");
	else{
		int carry=0, now=k, ans_size = 0;
		while(ans_size < 100){
			int temp = now*n + carry;
			ans[ans_size++] = now;
			//printf("%d\n", now);
			if(temp%10 == k && temp/10 == 0 && now != 0) break;

			now = temp%10;
			carry = temp/10;
		}

		int s = ans_size-1;
		while(ans[s] == 0) s--;
		//printf("%d %d\n", now, carry);
		for(int i=s; i>=0; i--) printf("%d", ans[i]);
	}
	return 0;
}