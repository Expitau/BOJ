/*
references : https://amugelab.tistory.com/212

*/

#include <iostream>
#include <algorithm>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

using pii = pair<int, int>;

int n, t;
vector<pii> p;
vector<int> l, r; // left pos, right pos
int forbiden[10010]; // forbied (forbiedn[i], l[i])
int C[10010], Cli[10010];
int ln, rn;

void input(){
    int a, b;
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        p.push_back({a, b-t});
        l.push_back(a);
        r.push_back(b-t);
    }
    sort(p.begin(), p.end());
    sort(l.begin(), l.end()); l.erase(unique(l.begin(), l.end()), l.end());
    sort(r.begin(), r.end()); r.erase(unique(r.begin(), r.end()), r.end());
    ln = l.size(); rn = r.size();
    for(int i=0; i<ln; i++) forbiden[i] = l[i];
    for(int i=0; i<rn; i++){ C[i]=r[i]+t; Cli[i]=ln-1;}
}

bool solve(){
    for(int i=n-1, li = ln-1; i>=0; li--){ // 각구간의 역순서대로 방문
        //cout << "i : " << i << "\n";
        int nexti, lastj = i;
        for(nexti=i; nexti>=0 && p[i].first == p[nexti].first; nexti--);
        for(int j=rn-1; j>=0 && p[i].first <= r[j]; j--){
            //cout << "i, j : " << li << ", " << j << "\n";
            for(;lastj>nexti && r[j] < p[lastj].second;lastj--) // 구간에 속하는 개수 세기
            if(lastj<=nexti) break;
            //cout << "cnt : " << lastj-nexti << "\n";
            //cout << "C : " << C[j] << "\n";
            for(int k = 0; k < lastj-nexti; k++){ // scheduling
                C[j] -= t; //t만큼 띄우기
                while(1)
                {
                    // C[j] 현재 끝점이 forbiden에 속한다면 계속 미루기
                    for(; Cli[j] > 1 && C[j] < l[Cli[j]-1] && C[j] <= forbiden[Cli[j]]; Cli[j]--);  //C[j]가 속할수 있는 forbiden영역으로
                    if(forbiden[Cli[j]] >= C[j] || C[j] >= l[Cli[j]] || C[j] < p[i].first) break;
                    C[j] = forbiden[Cli[j]]; //forbiden에 속한다면 C[j]를 움직이고 다시 확인
                }
                if(C[j] < p[i].first) return false;
            }
            forbiden[li] = min(forbiden[li], C[j] - t);
        }
        i = nexti;
    }
    return true;
}

int main(){
    FAST_IO;
    input();
    cout << (solve()?"yes":"no"); 
    return 0;
}