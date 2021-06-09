#include <iostream>
#include <vector>
#include <algorihtm>
#include <queue>
#include <string>
using namespace std;

queue<pair<string, int>> que; 
int visit[220];
string ans[220];

void solve(int k){
    que.push({"1", 1});

    while(1){
        string now = que.front().first;
        int now_int = que.front().second;
        que.pop();

        int next_int = (now_int*2)%k;
        if(!visit[next_int]){
            visit[next_int] = 1;
            que.push({now+"0"}, next_int);
        }
        next_int = (next_int + 1)%k;

        if(!visit[next_int]){
            visit[next_int] = 1;
            que.push({now+"1"}, next_int);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
    cin>>n;
	while(n--){
        int k;
        cin>>k;
        solve(k);
    } 
    return 0; 
}
