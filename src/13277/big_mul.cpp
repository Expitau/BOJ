#include <cstdio>
#include <complex>
#include <algorithm>
#include <vector>
using namespace std;
typedef complex<double> base;

void fft(vector<base> &a, bool inv){
	int n = (int) a.size();
	vector<base> b = a;
	for(int i=0; i<n; i++){
		int sz = n, shift = 0, idx = i;
		while(sz > 1){
			if(idx & 1) shift += sz >> 1;
			idx >>= 1;
			sz >>= 1;
		}
		a[shift + idx] = b[i];
	}
	for(int i=1; i<n; i<<=1){
		double x = inv ? M_PI / i : -M_PI / i;
		base w = {cos(x), sin(x)};
		for (int j=0; j<n; j+=i<<1){
			base th = {1, 0};
			for (int k=0; k<i; k++){
				base tmp = a[i+j+k] * th;
				a[i+j+k] = a[j+k] - tmp;
				a[j+k] += tmp;
				th *= w;
			}
		}
	}
	if (inv){
		for(int i=0; i<n; i++){
			a[i] /= n;
		}
	}
}

void multiply(vector<base> & a, vector<base> & b){
	int n = (int) max(a.size(), b.size());
	int i=0;
	while((1<<i) < (n<<1)) i++;
	n = 1<<i;
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);
	for(int i=0; i<n; i++){
		a[i] *= b[i];
	}
	fft(a, true);
}

vector<base> a, b;
char str[300100];

int main(){
	scanf("%s", str);
	for(int i=0; str[i]; i++) 
		a.push_back(str[i]-'0');
	scanf("%s", str);
	for(int i=0; str[i]; i++)
		b.push_back(str[i]-'0');
	multiply(a, b);
	for(auto it : a) printf("%d", (int)real(it));
	return 0;
}
