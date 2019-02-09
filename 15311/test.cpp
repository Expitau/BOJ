#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int check[100];
int main(){
	vector<int> v;
	int n, flag = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) v.push_back(i);
	do{
		for(int i=1; i<=n*n; i++) check[i] = 0;
		for(int i=0; i<n; i++){
			int sum = 0;
			for(int j=i; j<n; j++){
				sum += v[j];
				check[sum] = 1;
			}
		}
		for(int i=1; i<=n*(n+1)/2+1; i++){
			if(check[i] == 0){
				flag = max(flag, i);
				break;
			}
		}
	}while(next_permutation(v.begin(), v.end()));
	printf("%d", flag-1);
	return 0;
}
