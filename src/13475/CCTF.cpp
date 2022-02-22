#include <iostream>
#include <algorithm>
using namespace std;

class Person{
public:
	int a, b, n;
	Person(int A=0, int B=0, int N=0){a=A;b=B;n=N;}
	void input(int N){n = N; cin >> a >> b;}
};

Person arr[100100];
int max_arr[100100], ans[100100];
int N;

void input(){
	cin >> N;
	for(int i=0; i<N; i++) arr[i].input(i);
	sort(arr, arr+N, [](Person A, Person B){return A.b<B.b;});

	max_arr[0] = arr[0].a;
	for(int i=1; i<N; i++) max_arr[i] = max(max_arr[i-1], arr[i].a);
}

int find_minmax(int last_min){
	return lower_bound(max_arr, max_arr+N, last_min) - max_arr;
}

void solve(){
	int now = N-1;
	while(now >= 0){
		int next = now, last_min = arr[now].a;
		while(find_minmax(last_min) < next){
			int temp = find_minmax(last_min);
			for(int i=temp; i<next; i++) last_min = min(last_min, arr[i].a);
			next = temp;
		}
		for(int i=next; i<=now; i++) ans[arr[i].n] = now;
		now = next-1;
	}

	for(int i=0; i<N; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	solve();
	
	return 0;
}
