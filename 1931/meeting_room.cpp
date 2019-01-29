#include <cstdio>
#include <algorithm>
using namespace std;

class data{
public:
    int s, e;
    data(int _s=0, int _e=0):s(_s),e(_e){}
    bool operator<(const data & D)const{
        if(e != D.e) return e < D.e;
        return s < D.s;
    }
};

data c[200000];

int main(){
    int n, now = 0, count = 1;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d %d", &c[i].s, &c[i].e);
    sort(c, c+n);
    for(int i=1; i<n; i++){
        if(c[now].e <= c[i].s){
            count++;
            now = i;
        }
    }
    printf("%d\n", count);
    return 0;
}