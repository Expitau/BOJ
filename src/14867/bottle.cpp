#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int a, b, c, d, temp = -1;
int arr[100001][5];

queue<pair<int, int>> que;

int & func(int A, int B){
	if(A == 0) return arr[B][0];
	if(A == a) return arr[B][1];
	if(B == 0) return arr[A][2];
	if(B == b) return arr[A][3];
	return arr[0][4];
}

int main(){
	scanf("%d %d %d %d", &a, &b ,&c ,&d);
	for(int i=0; i<=max(a, b); i++) for(int j=0; j<5; j++) arr[i][j] = -1;
	que.push({0, 0});
	arr[0][0] = 0;
	while(!que.empty()){
		int A = que.front().first, B = que.front().second, rk = func(A, B);
		que.pop();
		if(func(A, 0) == -1){
			func(A, 0) = rk + 1;
			que.push({A, 0});
		}if(func(0, B) == -1){
			func(0, B) = rk + 1;
			que.push({0, B});
		}if(func(a, B) == -1){
			func(a, B) = rk + 1;
			que.push({a, B});
		}if(func(A, b) == -1){
			func(A, b) = rk + 1;
			que.push({A, b});
		}if(func(A+min(a-A, B), B-min(a-A, B)) == -1){
			func(A+min(a-A, B), B-min(a-A, B)) = rk+1;
			que.push({A+min(a-A, B), B-min(a-A, B)});
		}if(func(A-min(A, b-B), B+min(A, b-B)) == -1){
			func(A-min(A, b-B), B+min(A, b-B)) = rk+1;
			que.push({A-min(A, b-B), B+min(A, b-B)});
		}
	}
	printf("%d\n", func(c,d));
	return 0;
}
