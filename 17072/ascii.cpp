#include <cstdio>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int r, g, b;
			scanf("%d %d %d", &r, &g, &b);
			int I = 2126*r + 7152*g + 722*b;
			if(I<510000) printf("#");
			else if(I<1020000) printf("o");
			else if(I<1530000) printf("+");
			else if(I<2040000) printf("-");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}
