#include <cstdio>
using namespace std;
const int mod = 1000000;
int arr[5005], d[5005];
char str[5005];
int main(){
	int sz=0;
    scanf("%s", str+2);
    for(sz=2; str[sz]; sz++) arr[sz] = str[sz]-'0';
    sz--;
	d[0] = d[1] = 1;
	for(int i=2; i<=sz; i++){
        if(arr[i] != 0) d[i] += d[i-1];
		if(arr[i] + arr[i-1]*10 <= 26 && arr[i-1] > 0) d[i] += d[i-2];
        d[i]%=mod;
	}
	printf("%d", d[sz]);
	return 0;
}
