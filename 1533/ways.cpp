#include <cstdio>
using namespace std;
using ll = long long;
const ll MOD = 1000003;

ll A[50][50], res[50][50], temp[50][50];
ll n, s, e, t;

void zero(){
    for(int i=0; i<n*5; i++){
        res[i][i] = 1;
    }
}

void square(){
    for(int i=0; i<n*5; i++){
        for(int j=0; j<n*5; j++){
            ll t = 0;
            for(int k=0; k<n*5; k++){
                t = (t+(res[i][k]*res[k][j])%MOD)%MOD;
            }
            temp[i][j] = t;
        }
    }
    for(int i=0; i<n*5; i++){
        for(int j=0; j<n*5; j++){
            res[i][j] = temp[i][j];
        }
    }
}

void mul(){
    for(int i=0; i<n*5; i++){
        for(int j=0; j<n*5; j++){
            ll t = 0;
            for(int k=0; k<n*5; k++){
                t = (t+(res[i][k]*A[k][j])%MOD)%MOD;
            }
            temp[i][j] = t;
        }
    }
    for(int i=0; i<n*5; i++){
        for(int j=0; j<n*5; j++){
            res[i][j] = temp[i][j];
        }
    }
}

void pow(int T){
    if(T == 0){
        zero();
        return;
    }
    pow(T/2);
    square();
    if(T%2) mul();
}

int main(){
    scanf("%lld %lld %lld %lld", &n, &s, &e, &t);
    for(int i = 0; i<n; i++){
        for(int j=0; j<4; j++){
            A[i*5+j+1][i*5+j] = 1;
        }
        for(int j=0; j<n; j++){
            int time;
            scanf("%1d", &time);
            if(time != 0)
                A[i*5][j*5+time-1] = 1;
        }
    }

    pow(t);

    printf("%lld", res[(s-1)*5][(e-1)*5]);
    return 0;
}