#include <cstdio>
bool nprime[1000100];

int main(){
	for(int i=2; i<=10000; i++){
		if(nprime[i]) continue;
		for(int k=i*i; k<=1000000; k+=i) nprime[k] = 1;
	}
	while(1){
		int a;
		scanf("%d", &a);
		if(!a) break;
		for(int i=2; i<=a; i++){
			if(!nprime[i]&&!nprime[a-i]){
				printf("%d = %d + %d\n", a, i, a-i);
				break;
			}
		}
	}
	return 0;
}
