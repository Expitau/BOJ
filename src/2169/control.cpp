#include <cstdio>
#include <algorithm>
using namespace std;
long long visit[1010][1010], d[1010][1010], arr[1010][1010];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%lld", arr[i] + j);
	d[0][0] = arr[0][0];
	for(int i=1; i<m; i++)
		d[0][i] = d[0][i-1] + arr[0][i];
	
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			long long sum = d[i-1][j];
			for(int k=j; k>=0; k--){
				sum += arr[i][k];
				if(visit[i][k]){
					d[i][k] = max(d[i][k], sum);
				}else{
					visit[i][k] = 1;
					d[i][k] = sum;
				}
			}
			sum = d[i-1][j];
			for(int k=j; k<m; k++){
				sum += arr[i][k];
				if(visit[i][k]){
					d[i][k] = max(d[i][k], sum);
				}else{
					visit[i][k] = 1;
					d[i][k] = sum;
				}
			}
		}
	}
	printf("%lld", d[n-1][m-1]);
	return 0;
}	
