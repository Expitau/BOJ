#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

using pii = pair<int, int>;

string s1, s2;
int lcs[2][10010];
int M[10010];
int len1, len2;

pii get_path(pii start, pii end){
    int m = (start.second + end.second)/2;
    for(int i=0; i<10010; i++) M[i] = lcs[0][i] = lcs[1][i] = 0;
    for(int i=start.first+1; i<=end.first; i++){
        for(int j=start.second+1; j<=m; j++){
            lcs[i%2][j] = max(lcs[i%2][j-1], lcs[(i+1)%2][j]);
            if(s1[i-1] == s2[j-1]) 
                lcs[i%2][j]  = max(lcs[(i+1)%2][j-1] + 1, lcs[i%2][j]);
        }
        M[i] = lcs[i%2][m];
    }

    for(int i=0; i<10010; i++) lcs[0][i] = lcs[1][i] = 0;
    for(int i=end.first-1; i>=start.first; i--){
        for(int j=end.second-1; j>=m; j--){
            lcs[i%2][j] = max(lcs[(i+1)%2][j], lcs[i%2][j+1]);
            if(s1[i] == s2[j]) 
                lcs[i%2][j]  = max(lcs[(i+1)%2][j+1] + 1, lcs[i%2][j]);
        }
        M[i] += lcs[i%2][m];
    }

    int maxM = M[start.first], maxI = start.first;
    //cout << "!!!! " ;
    for(int i=start.first; i<=end.first; i++){
        if(M[i] >= maxM){
            maxM = M[i];
            maxI = i;
        }
        //cout << M[i] << " ";
    }
    //cout << "\n" << maxI << "\n";
    return {maxI, maxM};
}

void path(pii start, pii end){
    //cout << "!! " << start.first << " " << start.second << " " << end.first << " " << end.second << "\n";

    if(start.second >= end.second) return;
    if(start.second + 1 == end.second){
        for(int i=start.first; i<end.first; i++){
            if(s1[i] == s2[start.second]){
                cout << s2[start.second];
                break;
            }
        }
        return;
    }
    int m = (start.second + end.second)/2;
    int maxI = get_path(start, end).first;
    path(start, {maxI, m});
    path({maxI, m}, end);
}

int main(){
    FAST_IO;
    cin >> s1 >> s2;
    len1 = s1.size(), len2 = s2.size();
    cout << get_path({0,0}, {len1, len2}).second << "\n";
    path({0,0}, {len1, len2});
    return 0;
}


