#include <iostream>
using namespace std;
int main(){
	int t, x1, y1, r1, x2, y2, r2, d, r, nr;
	cin>>t;
	for(int i = 0; i < t; i++){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		r=(r1+r2)*(r1+r2);
		nr=(r1-r2)*(r1-r2);
		if(d==0){
			if(r1==r2) cout<<"-1\n";
			else cout<<"0\n";
		}else{
			if(d==r || d==nr) cout<<"1\n";
			else if(d < r && d>nr)cout<<"2\n";
			else cout<<"0\n";
		}
	}
}