#include <cstdio>
#include <vector>
using namespace std;

char str1[1010], str2[2020];
int d[1010][1010], path[1010][1010], n1, n2;
vector<char> ans1, ans2;

void get_ans(int i, int j){
	if(path[i][j] == -1) return;
	if(path[i][j] == 0){
		get_ans(i-1, j-1);
		ans1.push_back(str1[i]);
		ans2.push_back(str2[j]);
	}else if(path[i][j] == 1){
		get_ans(i-1, j);
		ans1.push_back(str1[i]);
	}else{
		get_ans(i, j-1);
		ans2.push_back(str2[j]);
	}
}

int main(){
	scanf("%d", &n1);
	for(int i=1; i<=n1; i++)
		scanf(" %c", str1+i);
	scanf("%d", &n2);
	for(int i=1; i<=n2; i++)
		scanf(" %c", str2+i);

	for(int i=0; i<=n1; i++) path[i][0] = -1;
	for(int i=0; i<=n2; i++) path[0][i] = -1;
	int Mi=0, Mj=0;
	for(int i=1; i<n1; i++){
		for(int j=1; j<n2; j++){
			d[i][j] = d[i-1][j-1];
			if(str1[i] == str2[j]) d[i][j] += 3;
			else d[i][j] -= 2;
			
			if(d[i][j] < d[i-1][j] - 2){
				path[i][j] = 1;
				d[i][j] = d[i-1][j] - 2;
			}

			if(d[i][j] < d[i][j-1] - 2){
				path[i][j] = 2;
				d[i][j] = d[i][j-1] - 2;
			}
			if(d[i][j] <= 0){
				d[i][j] = 0;
				path[i][j] = -1;
			}
			if(d[i][j] > d[Mi][Mj]){
				Mi = i; Mj = j;
			}
		}
	}
	printf("%d\n", d[Mi][Mj]);
	get_ans(Mi, Mj);
	for(auto it : ans1) printf("%c", it);
	printf("\n");
	for(auto it : ans2) printf("%c", it);
	return 0;
}
