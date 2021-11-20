#include <cstdio>
#include <algorithm>
using namespace std;
int d[550][550], arr[550];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", arr+i);
			if(i != 0) arr[i] += arr[i-1];
		}
		for(int i=1; i<n; i++){
			for(int j=0; j+i<n; j++){
				d[j][j+i] = 2e9;
				for(int k=0; k<i; k++) d[j][j+i] = min(d[j][j+i], d[j][j+k]+d[j+k+1][j+i]);
				d[j][j+i] += arr[j+i];
				if(j != 0) d[j][j+i] -= arr[j-1];
			}	
		}
		printf("%d\n", d[0][n-1]);
	}
	return 0;
}
