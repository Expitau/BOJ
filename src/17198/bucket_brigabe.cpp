#include <cstdio>
#include <queue>
using namespace std;
class data{
public:
	int x, y, t;
	data(){}
	data(int X, int Y, int T){x=X; y=Y; t=T;}
};
queue<data> que;
int visit[20][20], sx, sy, ex, ey, rx, ry;
int arr[2][4] = {{0,0,1,-1}, {1,-1,0,0}};
int main(){
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			char ch;
			scanf(" %c", &ch);
			if(ch == 'B') sx = i, sy = j;
			else if(ch == 'R') rx = i, ry = j;
			else if(ch == 'L') ex = i, ey = j;
		}
	}
	que.push({sx, sy, 0});
	while(!que.empty()){
		int nx = que.front().x, ny = que.front().y, nt = que.front().t;
		que.pop();
		if(nx == ex && ny == ey){
			printf("%d", nt-1);
			break;
		}
		for(int i=0; i<4; i++){
			int nX = nx + arr[0][i];
			int nY = ny + arr[1][i];
			if(nX <= 0 || nX > 10 || nY <= 0 || nY > 10 || visit[nX][nY]) continue;
			if(nX == rx && nY == ry) continue;
			visit[nX][nY] = 1;
			que.push({nX, nY, nt+1});
		}
	}
	return 0;
}
