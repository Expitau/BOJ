#include <cstdio>
using namespace std;

int arr[7];

int main(){
	int ans = 0;
	for(int i=1; i<=6; i++)
		scanf("%d", arr+i);
	ans += arr[6] + arr[5] + arr[4] + arr[3]/4 + (bool)(arr[3]%4);
	
    int a1 = arr[5]*11, a2 = arr[4]*5;
	switch(arr[3]%4){
	case 1:
		a1 += 7;
		a2 += 5;
		break;
	case 2:
		a1 += 6;
		a2 += 3;
		break;
	case 3:
		a1 += 5;
		a2 += 1;
	}
    
    if(a2 >= arr[2]){
		a1 += (a2 - arr[2])*4;	
    }else{
		arr[2] -= a2;
		ans += arr[2]/9 + (bool)(arr[2]%9);
		a1 += 36 - (arr[2]%9)*4;
	}
	if(a1 < arr[1]){
		arr[1] -= a1;
		ans += arr[1]/36 + (bool)(arr[1]%36);
	}
	printf("%d", ans);
	return 0;
}
