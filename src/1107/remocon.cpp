#include <cstdio>
inline int abs(int k){return k<0?-k:k;}
bool impossible[11];

bool func(int n){
	if(n < 0) return false;
	if(n == 0) return !impossible[0];
	while(n != 0){
		if(impossible[n%10]) return false;
		n /= 10;
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	while(m--){
		int temp;
		scanf("%d", &temp);
		impossible[temp] = 1;
	}
	for(int i=0;;i++){
		int a = n-i, b = n + i;
		if(a == 100 || b == 100 || func(a) || func(b)){
			printf("%d", i);
			break;
		}
	}
	return 0;
}

