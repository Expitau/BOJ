#include <cstdio>
#include <algorithm>
using namespace std;
using pii = pair<int, int>

char str1[7010], str2[7010];
pii table[7010][2];
char ans[7010];
int ans_end;


void lcs(pii s, pii e){
    int sx = s.first, sy = s.second;
    int ex = e.first, ey = e.second;
    int mx = (sx + ex)/2;
    for(int now=s+1; now<=e; now++){

    }
}

int main(){
    scanf("%s %s", str1+1, str2+1);
    int len1 = strlen(str1+1), len2 = strlen(str2+1);
    lcs(pii(0,0), pii(len1, len2));
    
    return 0;
}
