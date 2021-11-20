#include <cstdio>
using namespace std;

int arr[(1<<25)/32];

int main(){
	int temp;
	while(scanf("%d", &temp) != EOF){
		int q = temp/32, r = 1 << (temp % 32);
		if(!(arr[q]&r)){
			arr[q] += r;
			printf("%d ", temp);
		}
	}
	return 0;
}
