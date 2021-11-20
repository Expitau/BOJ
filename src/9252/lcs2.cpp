#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1010][1010];
char str1[1010], str2[1010];
void print(int i, int j){
	if(i <= 0 || j <= 0) return;
	if(d[i][j] == d[i-1][j]) print(i-1, j);
	else if(d[i][j] == d[i][j-1]) print(i, j-1);
	else{
		print(i-1, j-1);
		printf("%c", str1[i-1]);
	}
}
int main(){
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i=1; i<=len1; i++){
		for(int j=1; j<=len2; j++){
			if(str1[i-1] == str2[j-1]) d[i][j] = d[i-1][j-1]+1;
			else d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}
	printf("%d\n", d[len1][len2]);
	print(len1, len2);
	return 0;
}
