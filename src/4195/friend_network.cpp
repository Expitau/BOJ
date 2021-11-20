#include <iostream>
#include <string>>
using namespace std;

unordered_map<string, int> Person;
int par[100100], size[100100];

void addPerson(string & str){
	if(Person.find(str) == Person.end()){
		int idx = Person.size()+1;
		par[idx] = idx;
		size[idx] = 1;
		Person[str] = idx;
	}
}

int getPar(int n){
	if(par[n] == n) return n;
	return par[n] = getPar(par[n]);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		Person.clear();
		int f;
		cin >> f;
		while(f--){
			string str1, str2;
			cin >> str1 >> str2;
			addPerson(str1);
			addPerson(str2);
			int a = Person[str1], b = Person[str2];
			if(getPar(a) != getPar(b)){
				size[getPar(b)] += size[getPar(a)];
				par[getPar(a)] = getPar(b);
			}
			cout << size[getPar(a)] << "\n";
		}
	}	
	return 0;
}
