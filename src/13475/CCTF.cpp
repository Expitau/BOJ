#include <cstdio>
#include <algorithm>
using namespace std;

class Person{
public:
	int a, b, n;
	Person(int A=0, int B=0, int N=0){a=A;b=B;n=N;}
	
	void input(){
		scanf("%d %d", &a, &b);
	}
};


Person arr[100100];
int ans[100100], ans_print[100100];
int max_idx[100100];
int max_val[100100];
int max_info[100100];
int max_cnt = 0, N;

int main(){
	
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		arr[i].input();
		arr[i].n = i;
	}
	sort(arr, arr+N, [](const Person & A, const Person & B)->bool{
		if(A.b != B.b) return A.b<B.b; return A.a<B.a;});
	
	
	//update max
	max_idx[0] = 0;
	max_val[0] = arr[0].a;
	max_info[0] = -1;
	for(int i=1; i<N; i++){
		if(max_val[max_cnt] < arr[i].a){
			max_cnt++;
			max_idx[max_cnt] = i;
			max_val[max_cnt] = arr[i].a;
			max_info[max_cnt] = -1;
		}
	}
	
	for(int i=0; i<=max_cnt; i++){
		printf("!!%d %d\n", max_idx[i], max_val[i]);
	}
	
	// find ans
	for(int i=N-1; i>=0; i--){
		// 나보다 큰 첫번쨰 MAX 찾기
		int k = upper_bound(max_val, max_val+max_cnt+1, arr[i].a) - max_val;
		
		printf("haha : %d %d %d %d\n", arr[i].a, k, max_val[k], max_info[k]);
		// ans update
		if(k == 0 || max_info[k-1] == -1){
			ans[i] = i;
		}else{
			ans[i] = ans[max_info[k-1]];
		}
		
		// 나보다 큰 MAX들에 나의 정보 밖기 (없다면)
		for(int j=k; j<=max_cnt && max_info[j] == -1; j++){
			max_info[j] = i;
		}
	}
	
	// change idx
	for(int i=0; i<N; i++){
		ans_print[arr[i].n] = ans[i];
	}
	
	for(int i=0; i<N; i++) printf("%d\n", ans_print[i]);
	
	return 0;
}
