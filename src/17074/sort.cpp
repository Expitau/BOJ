#include <cstdio>
using namespace std;
int arr[100100];
int main(){
	int n, i, cnt = 0, temp;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	for(int i=1; i<n; i++){
		if(arr[i] < arr[i-1]){
			cnt++;
			temp = i;
		}
	}
	if(cnt > 1) printf("0");
	else if(cnt == 1){
		int ans = 0;
		if(temp == n-1) ans++;
		else if(arr[temp-1] <= arr[temp+1]) ans++;
		if(temp == 1) ans++;
		else if(arr[temp-2] <= arr[temp]) ans++;
		printf("%d", ans);
	}else printf("%d", n);
	return 0;
}
