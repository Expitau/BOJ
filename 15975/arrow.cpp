#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> inArr;
vector<vector<int>> dots;
vector<int> color;

int main(){
    int n;
    scanf("%d", &n);
    inArr.resize(n); color.resize(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &inArr[i].first, &inArr[i].second);
        color[i] = inArr[i].second;
    }
    sort(color.begin(), color.end());
    color.erase(unique(color.begin(), color.end()), color.end());
    dots.resize(color.size());
    for(int i=0; i<n; i++){
        int k = lower_bound(color.begin(), color.end(), inArr[i].second) - color.begin();
        dots[k].push_back(inArr[i].first);
    }
    ll ans = 0;
    for(int i=0; i<dots.size(); i++){
        sort(dots[i].begin(), dots[i].end());
        for(int j=0; j<dots[i].size(); j++){
            int mx = 0;
            if(j > 0) mx = max(mx, dots[i][j] - dots[i][j-1]);
            if(j+1 < dots[i].size()) mx = max(mx, dots[i][j+1] - dots[i][j]);
            ans += mx;
        }
    }
    printf("%lld", ans);
    return 0;
}
