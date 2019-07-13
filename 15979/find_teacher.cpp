#include <cstdio>
using namespace std;

int gcd(int a, int b){
	while(b != 0){
        int n = a%b;
        a = b;
        b = n;
	}
	return a;
}

int main(){
	int n , m, ans;
	scanf("%d %d", &n, &m); 
	if(n<0) n=-n; 
	if(m<0) m=-m;
    if(n == 0 && m == 0) ans = 0;
    else if(n == 0 || m == 0){
        if(n == 0 && m == 1) ans = 1;
        else if(m == 0 && n == 1) ans = 1;
        else ans = 2;
    }else if(gcd(n, m) == 1) ans = 1;
	else ans = 2;
	printf("%d", ans);
	return 0;
}
