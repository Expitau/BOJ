#include <iostream>
using namespace std;

const int offset = 210;
int arr[420];

void push(int idx, int b){
    arr[idx+offset] = b;
}

int get(int idx){
    return arr[idx+offset];
}

int change(int i1, int i2){
    if(get(i2) != 0 || get(i2+1) != 0) return 1;
    if(get(i1) == 0 || get(i1+1) == 0) return 1;
    
    push(i2, get(i1)); push(i1, 0);
    push(i2+1, get(i1+1)); push(i1+1, 0);
    return 0;
}

void print_arr(int t, int n){
    for(int i=t; i<=n*2; i++){
        cout << get(i) << " ";
    }
    cout << "\n=================\n";
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n*2; i++){
        if(i%2) push(i, 2);
        else push(i, 1);
    }
    //print_arr(-5, n);
    int r;
    for(r=0; r<n; r++){
        int i1, i2;
        cin >> i1 >> i2;
        if(i1 == -100) break;
        if(change(i1, i2)) break;
        //print_arr(-5, n);
    }
    cout << r << "th\n";
    print_arr(-5, n);

    
    return 0;
}
/*
10
18 to -1
3 to 18
14 to 3
11 to 14
6 to 11
10 to 6
4 to 10
15 to 4
0 to 15
19 to 0

*/