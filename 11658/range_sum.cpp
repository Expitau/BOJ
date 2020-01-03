#include <cstdio>
using namespace std;

int tree[1030][1030], arr[1030][1030], n, m;

void update(int x, int y, int diff){
	for(int i = x; i <= n; i += (i & -i)){
		for(int j = y; j <= n; j += (j & -j)){
			tree[i][j] += diff;
		}
	}
}

int sum(int x, int y){
	int res = 0;
	for(int i = x; i > 0; i -= (i & -i)){
		for(int j = y; j > 0; j -= (j & -j)){
			res += tree[i][j];
		}
	}
	return res;
}

int range_sum(int x1, int y1, int x2, int y2){
	int res = 0;
	res += sum(x2, y2);
	res -= sum(x1-1, y2);
	res -= sum(x2, y1-1);
	res += sum(x1-1, y1-1);
	return res;
}


int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", arr[i] + j);
			update(i, j, arr[i][j]);
		}
	}
	
	for(int i=0; i<m; i++){
		int type;
		scanf("%d", &type);
		if(type){
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", range_sum(x1, y1, x2, y2));
		}else{
			int x, y, change;
			scanf("%d %d %d", &x, &y, &change);
			update(x, y, change - arr[x][y]);
			arr[x][y] = change;
		}
	}
	return 0;
}
