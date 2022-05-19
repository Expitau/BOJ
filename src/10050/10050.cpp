#include <iostream>
using namespace std;

void print(int a, int b, int offset = 0){
    cout << a + offset << " to " << b + offset << "\n";
}

void solve(int s, int n){
    if(n <= 2) return;
    else if(n == 3){
        print(2, -1, s);
        print(5, 2, s);
        print(3, -3, s);
    }else if(n == 5){
        print(8, -1, s);
        print(3, 8, s);
        print(6, 3, s);
        print(0, 6, s);
        print(9, 0, s);
    }else if(n == 6){
        print(10, -1, s);
        print(7, 10, s);
        print(2, 7, s);
        print(6, 2, s);
        print(0, 6, s);
        print(11, 0, s);
    }else if(n == 7){
        print(12, -1, s);
        print(5, 12, s);
        print(8, 5, s);
        print(3, 8, s);
        print(9, 3, s);
        print(0, 9, s);
        print(13, 0, s);
    }else{
        print(2*n-2, -1, s);
        print(3, 2*n-2, s);
        solve(s+4, n-4);
        print(0, 2*n-5, s);
        print(2*n-1, -0, s);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    solve(0, n);
    return 0;
}