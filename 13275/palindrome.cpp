#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[100100], str2[200100];
int d[200100];

int main(){
	scanf("%s", str);
	int n = strlen(str);
	for(int i=0; i<n; i++){
		str2[i*2] = str[i];
		str2[i*2+1] = '#';
	}
	int p = -1, l = -1, ans = 0;
	for(int i=0; i<n*2; i++){
		if(l >= i)
			d[i] = min(d[2*p-i], l-i);
		while(i-d[i]-1>=0 && i+d[i]+1 < 2*n && str2[i-d[i]-1]==str2[i+d[i]+1])
			d[i]++;
		if(d[i]+i > l){
			l = d[i]+i;
			p = i;
		}
		if(i%2) ans = max(ans, d[i]+(d[i]%2));
		else ans = max(ans, d[i]+1-(d[i]%2));
	}
	printf("%d", ans);
	return 0;
}
