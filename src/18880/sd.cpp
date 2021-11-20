#include <iostream>
#include <string>
using namespace std;

char str[100100];
int oneG, oneS, two, n, min_d = 100100;


void update(int term, int before, int after){
  int oneN=0, twoN=0;
  if(before && after){
    oneN = (term+1)/2;
    twoN = (term+1)/3;
    min_d = min(term+1, min_d);
  }else if(after || before){
    oneN = term;
    twoN = term/2;
  }else{
    oneN = 100100;
    twoN = term-1;
  }
  
  if(oneG <= oneN){
    oneS = oneG;
    oneG = oneN;
  }else if(oneS <= oneN){
    oneS = oneN;
  }
  two = max(two, twoN);
}

int main(){
  cin >> n >> str+1;
  int before = 0;
  for(int i=1; i<=n; i++){
    if(str[i]-'0'){
      update(i-before-1, before>0, 1);
      before = i;
    }
  }
  update(n-before, before>0, 0);
  
  int ans = min(max(two, oneS), min_d);
  cout << ans;
  
  return 0;
}