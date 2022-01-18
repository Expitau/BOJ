#include <iostream>
#include <string>
using namespace std;

int main(){
    string str, ans1, ans2;
    cin >> str;
    
    for(int i=str.length()-1; i>=0; i--){
        int flag = 1;
        for(int j=0; j<i && flag; j++){
            if(str[j] < str[i]) flag = 0;
        }
        if(flag) ans1 += str[i];
        else ans2 = str[i] + ans2;
    }

    cout << ans1 << ans2;

    return 0;
}
