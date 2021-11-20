#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
char str[60];
int visit[60];
stack<int> stk, stk2;

int main(){
    int ans = 0;
    scanf("%s", str);
    for(int i=0; i<52; i++){
        int ncow = str[i] - 'A';
        if(visit[ncow]){
            while(stk.top() != ncow) stk2.push(stk.top()), ans++, stk.pop();
            stk.pop();
            while(!stk2.empty()) stk.push(stk2.top()), stk2.pop();
        }else visit[ncow] = 1, stk.push(ncow);
    }
    printf("%d", ans);
    return 0;
}
