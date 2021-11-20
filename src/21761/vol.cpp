#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> Arr[4];
ll Val[4];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin>>n>>k;
    for(int i=0; i<4; i++) cin>>Val[i];
    for(int i=0; i<n; i++){
        char temp1;
        ll k;
        cin >> temp1 >> k;
        Arr[temp1-'A'].push_back(k);
    }
    for(int i=0; i<4; i++){
        sort(Arr[i].begin(), Arr[i].end());
    }
    for(int i=0; i<k; i++){
        int idx = -1;
        for(int i=0; i<4; i++){
            if(Arr[i].empty()) continue;
            if(idx == -1) idx = i;
            if((*Arr[i].rbegin()) * Val[idx] > (*Arr[idx].rbegin())*Val[i])
                idx = i;
        }
        cout<<(char)('A'+idx)<<" "<<*Arr[idx].rbegin()<<"\n";
        Val[idx] += (*Arr[idx].rbegin());
        Arr[idx].erase(Arr[idx].end()-1);
    }
    return 0;
}
