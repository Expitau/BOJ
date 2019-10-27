#include <cstdio>
using namespace std;

int arr[2020];
bool d[2020][2020];

bool func1(int a, int b){
	if(a > b) return 1;
	return d[a][b];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", arr+i);
	}
	for(int i=1; i<=n; i++) d[i][i] = 1;
	for(int k=1; k<n; k++){
		for(int i=1; i<=n; i++){
			d[i][i+k] = (arr[i] == arr[i+k]) && func1(i+1, i+k-1);
		}
	}
	int m;
	scanf("%d", &m);
	while(m--){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", d[s][e]);
	}
	return 0;
}
